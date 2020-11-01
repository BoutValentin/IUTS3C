#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include "traitement.h"

/* 
Cette fontion li les arguments passer au programme pour determiner si l'utilisation est correcte et les arguments demande
*/
int readArgs( int argc, char const **argv, int *wantChar, int *wantWord, int *wantLignes){

     /* On demarre notre lecture au premier argument afin d'eviter l'executable */
     int i = 1;
     /* Permettra d'arreter la lecture en cas de parametre non correcte */
     int shouldBreak = 0;
     /* On met nos valeurs pointer par ces pointeurs a zero */
     *wantWord = 0;
     *wantLignes = 0;
     *wantChar =0;
     /* Tant qu'on a des arguments a lire */
     for(i = 1; i<argc && !shouldBreak;i++){
          int y = 1;
          /* Si le premier caractere du parametre n'est pas - alors on a finis de lire les parametres */
          if(argv[i][0]!='-') {
               shouldBreak = 1;
          }else{
               /* Sinon on fait de l'analyse en demarrant au second charactere */
               char c ;
               /* Tant on a des caracteres a lire */
               while((c = argv[i][y])){
                    /* Si le caractere est egale a w alors on veut voir le nombre de mot */
                    /* Si le caractere est egale a c alors on veut voir le nombre de char */
                    /* Si le caractere est egale a l alors on veut voir le nombre de ligne */
                    if(c=='w') *wantWord = 1;
                    else if(c=='c') *wantChar = 1;
                    else if(c=='l') *wantLignes = 1;
                    else {
                         /* Sinon le caractere n'est pas valide et on annule l'execution */
                         shouldBreak = 1;
                         /* On affiche notre message d'erreur */
                         printError();
                         return -1;
                    }
                    /* On incremente notre compteur */
                    ++y;
               }
          }
          
     }
     /* Si on le nombre d'arguments est de 1 alors on va lire sur l'entre standart et on veut tout */
     if(argc==1){
          *wantChar = 1;
          *wantWord = 1;
          *wantLignes = 1;
     }

     return i-1;
}


int main(int argc, char const **argv){

     int *wantChar = (int *) malloc(sizeof(int));
     int *wantWord = (int *) malloc(sizeof(int));
     int *wantLignes = (int *) malloc(sizeof(int));
     /* On verifie que l'allocation memoire c'est bien passer */
     if(wantChar==NULL||wantWord==NULL||wantLignes==NULL){
          perror("malloc");
          return;
     }
     /* On recupere le nombre d'argument lu valide */
     int numberRead = readArgs(argc, argv, wantChar, wantWord, wantLignes);

     int *nbChar = (int *) malloc(sizeof(int));
     int *nbMot = (int *) malloc(sizeof(int));
     int *nbLigne = (int *) malloc(sizeof(int));
     /* On verifie que l'allocation memoire c'est bien passer */
     if(nbChar==NULL||nbMot==NULL||nbLigne==NULL){
          perror("malloc");
          return;
     }
     /* Si un probleme a eu lieu on a return -1 donc on arrete l'execution du processus */
     if(numberRead==-1) return -1;
     /* Si on a lu aucun argument alors on utilise l'entre par default*/
     if(argc==1 || numberRead+1==argc){
          printf("Now using default enter \n");
          /* On initialise nos compteur a zero*/
          *nbChar = 0;*nbMot=0;*nbLigne=0;
          /* Traite le mot par le file descriptor*/
          traiter(0, nbChar,nbMot, nbLigne);
          printf("\nResults : \n");
          /* On realise l'affichage en fonction des parametres demande */
          if(*wantChar) printf("\t Number of Char : %d \n",*nbChar);
          if(*wantWord) printf("\t Number of Word : %d \n",*nbMot);
          if(*wantLignes) printf("\t Number of Lignes : %d \n",*nbLigne);
     }else{
          /* Pour chaque argument a lire selon le dernier parametre lu on effectue le traitement */
          while(numberRead<argc){
               /* On initialise nos compteur a zero*/
               *nbChar = 0;*nbMot=0;*nbLigne=0;
               /* On ouvre le fichier en parametre en lecture seule */
               int fd = open(argv[numberRead], O_RDONLY);
               /* On verifie que la fonction c'est bien deroule */
               if(fd==-1)  perror(argv[numberRead]);
               else {traiter(fd, nbChar,nbMot, nbLigne);
               printf("\nResults of: %s \n",argv[numberRead]);
               /* On realise l'affichage en fonction des parametres demande */
               if(*wantChar) printf("\t Number of Char : %d \n",*nbChar);
               if(*wantWord) printf("\t Number of Word : %d \n",*nbMot);
               if(*wantLignes) printf("\t Number of Lignes : %d \n",*nbLigne);
               }
               /* On incremente notre compteur */
               numberRead++;
          }
     }
     /* On retourne zero comme tout c'est bien passer */
     return 0;
}