#include "miroir.h"
#include "saisie.h"
#include <stdio.h>
#include <string.h>

/* Fonction testant si les parametres passer sont ceux attendus */
int testerParams(int argc, char const **argv){
     /* On demarre notre compteur a 1 pour eviter le nom de l'executable */
     int i = 1;
     int i2 = 0;
     /* Tant que l'on a des arguments a lire */
     while(i<argc){
          i2 = 0;
          /* Si le parametre ne commence pas par - alors le parametre n'est pas bon et on retourne 0 */
          if(argv[i][i2++]!='-') return 0;
          /* Pour chaque caractere des chaines de caracteres */
          while(argv[i][i2]){
               /* Si le caractere lu n'est ni s ni m alors il s'agit d'une mauvaise lettre et on retourne 0 */ 
               if(argv[i][i2]!='s' && argv[i][i2]!='m'){
                    return 0;
               }
               i2++;
          }
          i++;
     }
     /* Sinon les parametres sont bien ceux attendus */
     return 1;
}
int containOnlyChar(int argc, char const **argv, char c){
     /* On demarre notre compteur a 1 pour eviter le nom de l'executable */
     int i = 1;
     int i2 = 0;
     /* Tant que l'on a des arguments a lire */
     while(i<argc){
          i2 = 0;
          /* Si le parametre ne commence pas par - alors le parametre n'est pas bon et on retourne 0 */
          if(argv[i][i2++]!='-') 
          {
               if(i+1!=argc)return 0;
          }
          /* Pour chaque caractere des chaines de caracteres */
          while(argv[i][i2] && i+1!=argc){
               /* Si le caractere lu n'est ni s ni m alors il s'agit d'une mauvaise lettre et on retourne 0 */ 
               if(argv[i][i2]!=c){
                    return 0;
               }
               i2++;
          }
          i++;
     }
     /* Sinon les parametres sont bien ceux attendus */
     return 1;
}

int main(int argc, char const **argv){
     /* Si on a que l'executable alors il manque des parametres */
     if(argc <= 1) {
          printf("Mauvaise utilisation \n");
          return 1;
     }
     /* SI le nombre de parametre est de 1 et que cette argument est -s alors on effectue une saisie */
     if(argc==2 && (containOnlyChar(argc, argv, 's'))){
          printf("%s enter \n", saisie());
          return 0;
     }
     /* SI le nombre de parametre est de 1 et que cette argument est -m alors l'utilisation est mauvaise */
     if(argc==2 && (!strcmp(*(argv+1),"-m") || containOnlyChar(argc, argv ,'m'))){
          printf("Mauvaise utilisation \n");
          return 0;
     }
     /* SI le nombre de parametre est de 2 et que cette argument est -m et que l'argument suplementaire n'est pas -s alors on realise le mirroir de l'argument du dessus */
     if((argc==3 && ((!strcmp(*(argv+1),"-m") && strcmp(*(argv+2),"-s")) || containOnlyChar(argc,argv, 'm')))){
          printf("%s reverse \n", miroir(*(argv+2)));
          return 0;
     }
     /* SInon on teste si tout les parametres son correcte et on realise le mirroir de la saisie*/
     if((testerParams(argc,argv))){
          printf("%s reverse \n", miroir(saisie()));
          return 0;
     }else{
          /* SInon c'est une mauvaise utilisation */
          printf("Mauvaise utilisation \n");
          return 1;
     }
     return 0;
}