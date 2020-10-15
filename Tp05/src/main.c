#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include "traitement.h"

int readArgs( int argc, char const **argv, int *wantChar, int *wantWord, int *wantLignes){

     int i = 1;

     int shouldBreak = 0;
     int oneOut = 0;
          *wantWord = 0;
     *wantLignes = 0;
     *wantChar =0;
     for(i = 1; i<argc && !shouldBreak;i++){
          int y = 1;
          if(argv[i][0]!='-') {
               if(i==1) oneOut= 1;
               shouldBreak = 1;
               
          }else{

               char c ;
               while((c = argv[i][y])){
                    if(c=='w') *wantWord = 1;
                    else if(c=='c') *wantChar = 1;
                    else if(c=='l') *wantLignes = 1;
                    else {
                         shouldBreak = 0;
                         printError();
                         return -1;
                    }
                    y++;
               }
          }
          
     }
     if(oneOut==1 || argc==1){
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
     int numberRead = readArgs(argc, argv, wantChar, wantWord, wantLignes);

     int *nbChar = (int *) malloc(sizeof(int));
     int *nbMot = (int *) malloc(sizeof(int));
     int *nbLigne = (int *) malloc(sizeof(int));
     if(numberRead==-1) return -1;
     if(argc==1 || numberRead+1==argc){
          char * arr = (char*)calloc(1,sizeof(char));
          printf("Now using default enter \n");

          char c;
          int size = 0;
          while((c=getchar())!='\n'){
               size++;
               arr = (char *)realloc(arr, sizeof(char)*size);
               arr[size-1]=c;

          }
          arr[size] = '\r';
          FILE * create = fopen("./tmp.tmp","w+");
          fputs(arr, create);
          fclose(create);
          *nbChar = 0;*nbMot=0;*nbLigne=0;
          int fd = open("./tmp.tmp", O_RDONLY);
          if(fd==-1)  perror("./tmp.tmp");
          else {traiter(fd, nbChar,nbMot, nbLigne);
          printf("Results : \n");
          if(*wantChar) printf("\t Number of Char : %d \n",*nbChar);
          if(*wantWord) printf("\t Number of Word : %d \n",*nbMot);
          if(*wantLignes) printf("\t Number of Lignes : %d \n",*nbLigne);
          }
          remove("./tmp.tmp");
     }else{
          while(numberRead<argc){
               *nbChar = 0;*nbMot=0;*nbLigne=0;
               int fd = open(argv[numberRead], O_RDONLY);
               if(fd==-1)  perror(argv[numberRead]);
               else {traiter(fd, nbChar,nbMot, nbLigne);
               printf("Results of: %s \n",argv[numberRead]);
               if(*wantChar) printf("\t Number of Char : %d \n",*nbChar);
               if(*wantWord) printf("\t Number of Word : %d \n",*nbMot);
               if(*wantLignes) printf("\t Number of Lignes : %d \n",*nbLigne);
               }
               numberRead++;
          }
     }

     /* int fd = open("./testFile.txt", O_RDONLY);
     if(fd==-1) perror("./testFile.txt");
     traiter(fd,nbChar,nbMot, nbLigne);
     printf("Char: %d, Mot: %d, nbLigne: %d \n", *nbChar, *nbMot, *nbLigne); */
     return 0;
}