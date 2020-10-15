#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<unistd.h> 
#include "ligne_commande.h"
void execute_ligne_commande(){

     int *flag = (int *) malloc(sizeof(int));
     if(flag==NULL){
          perror("Problem malloc flag");
          return ;
     }
     int *nb = (int *) malloc(sizeof(int));
     if(nb==NULL){
          perror("Problem malloc nb");
          return ;
     }
     char ***tabOfCommand = ligne_commande(flag,nb);
     if(*flag==-1){
          perror("Error in command ligne \n");
          return ;
     }
     int res  = fork();
     if(res==-1){
          perror("Problem in fork");
          return ;
     }else if(res==0){
          if(*flag==1){
               close(STDOUT_FILENO); 
          }
          int i = execvp(tabOfCommand[0][0], tabOfCommand[0]);
          if(i==-1){
               return;
          }
     }else{
          if(*flag==0){
               fflush(stdout);
               wait(NULL);
          }else{
               printf("%d \n", res);
          }
          fflush(stdout);
     }
}
