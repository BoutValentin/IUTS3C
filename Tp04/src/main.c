#include "miroir.h"
#include "saisie.h"
#include <stdio.h>
#include <string.h>

int testerParams(int argc, char const **argv){
     int i = 1;
     int i2=0;
     while(i<argc){
          i2=0;
          if(argv[i][i2++]!='-') return 0;
          while(argv[i][i2]){
               if(argv[i][i2]!='s' && argv[i][i2]!='m'){
                    return 0;
               }
               i2++;
          }
          i++;
     }
     return 1;
}

int main(int argc, char const **argv){
     if(argc <= 1) {
          printf("Mauvaise utilisation \n");
          return 1;
     }
     if(argc==2 && !strcmp(*(argv+1),"-s")){
          printf("%s enter \n", saisie());
           return 0;
     }
     if((argc==3 && !strcmp(*(argv+1),"-m") && strcmp(*(argv+2),"-s"))){
          printf("%s reverse \n", miroir(*(argv+2)));
          return 0;
     }
     if((testerParams(argc,argv))){
          printf("%s reverse \n", miroir(saisie()));
          return 0;
     }else{
          printf("Mauvaise utilisation i \n");
          return 1;
     }
     return 0;
}