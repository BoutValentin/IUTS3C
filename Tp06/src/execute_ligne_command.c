#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<unistd.h> 
#include "ligne_commande.h"

void execute_ligne_commande(){

     /* On alloue une zone memoire et recupere son adresse dans une variable de type pointeur */
     int *flag = (int *) malloc(sizeof(int));
     /* On verifie que l'adressage memoire s'est bien passer */
     if(flag==NULL){
          perror("malloc");
          return ;
     }
     /* On alloue une zone memoire et recupere son adresse dans une variable de type pointeur */
     int *nb = (int *) malloc(sizeof(int));
     /* On verifie que l'adressage memoire s'est bien passer */
     if(nb==NULL){
          perror("malloc");
          return ;
     }
     /* On recupere toute les lignes de commandes lu par la fonction fournit */
     char ***tabOfCommand = ligne_commande(flag,nb);
     if(*flag<0){
          printf("Error in command ligne \n");
          return;
     }

     int res ;
     int i = 0;
     res = fork();
     /* On divise le programme en 'deux' processus et on verifie que le fork c'est bien passe*/
     if(res==-1){
          perror("fork");
          return ;
     }else if(res==0){
          /* Nous somme dans le processus enfant */
          /* Si le nombre de command lu est de zero alors on a rien a faire*/
          if(*nb==0)return;
          /* Si on a lu strictement une command on l'execute */
          if(*nb==1){
               /* Execution de la command et de ses arguments */
               execvp(tabOfCommand[0][0], tabOfCommand[0]);
               /* Si l'execution se passe bien le programme est remplace par celui de la command et ce qui est en dessous n'est jamais execute */
               perror("execvp");
               return;      
          }else{
               /* Sinon on a deux command a executer */
               /* On alloue un double array afin de stocker tout nos pipe suffisant. Cet array a la taille du nombre de command -1
                    car:
                         cm1        cm2        cmd3
                             [pipe]      [pipe]     
                */
               int **all_pip = malloc(((*nb)-1)*sizeof(int *));
               /* On verifie que l'adressage memoire s'est bien passer */
               if(all_pip == NULL){
                    perror("Error in allocating the array of pipe \n");
                    return ;
               }
               /* Pour chaque case de notre precedent tableau on alloue un tableau de deux cases afin de creer nos pipe*/
               int cpt = 0;
               while(cpt<((*nb)-1)){
                    all_pip[cpt] = malloc(sizeof(int)*2);
                    /* On verifie que l'adressage memoire s'est bien passer */
                    if(all_pip[cpt] == NULL){
                         perror("Error in allocating the array of pipe \n");
                         return;
                    }
                    /* On creer notre pipe */
                    if(pipe(all_pip[cpt])==-1){
                         perror("Error while trying to pipe");
                         return;
                    }
                    ++cpt;
               }
               /* Pour chaque command a executer*/
               while(tabOfCommand[i]!=NULL){
                    /* On creer un nouveau processus */
                    int forking = fork();
                    /* On verifier que le fork c'est bien passer */
                    if(forking<0){
                         perror("Fork failled \n");
                         return;
                    }
                    /* Pour chaque processus enfant */
                    if(forking==0){
                         /* Si on n'est pas a la premiere command lu */
                         if(i!=0){
                              /* On recupere l'entree du precent pipe et remplace par l'entree standart */
                              if(dup2(all_pip[i-1][0],0)<0){
                                   perror("Error in piping \n");
                                   return;
                              }
                         }    
                         /* Si on est pas a la derniere command on ecrit dans notre pipe */
                         if(i!=(*nb)-1){
                              if(dup2(all_pip[i][1],1)<0){
                                   perror("Error in piping \n");
                                   return;
                              }

                         }  
                         /* On ferme tout les pipes ouverts */
                         for(cpt = 0 ; cpt < i ; cpt++){
                              close(all_pip[cpt][0]);
                              close(all_pip[cpt][1]);
                         }          
                         /* On execute la command */
                         execvp(tabOfCommand[i][0], tabOfCommand[i]);
                         perror("Error in command ligne \n");
                         return;
                    }
                    i++;
               }
               /* On ecrit dans la sortie standart tout ce qui est dans le buffer*/
               fflush(stdout);
               /* On ferme tout les pipes ouverts */
               for(cpt = 0 ; cpt < ((*nb)-1) ; cpt++){
                    close(all_pip[cpt][0]);
                    close(all_pip[cpt][1]);
               }
               /* On attend que tout les processus enfants sont terminer*/
               for(cpt = 0 ; cpt < ((*nb)-1) ; cpt++){
                    wait(NULL);
               }
          }
          /* On attend finalement que le dernier processus enfants sois terminer*/
          wait(NULL);
     }else{
          /*Si le flag est a zero alors on doit attendre l'execution du parent */
          if(*flag==0){
               fflush(stdout);
               wait(NULL);
          /* Sinon on print juste le pid de l'enfant et on n'attend pas la fin de l'execution */
          }else if(*flag>0){
               fflush(stdout);
               printf("%d \n", res);
          }
          /* On ecrit dans la sortie standart tout ce qui est dans le buffer*/
          fflush(stdout);
          /* On libere le tableau de command alloue et les deux pointeurs*/
          libere(tabOfCommand);
          free(flag);
          free(nb);
     }
}
