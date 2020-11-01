#include <stdio.h>
#include <stdlib.h>
/* 
Realise la saisie d'une chaine de caractere dans l'entree standart et la retoune sous forme de tableau
*/
char * saisie(){
     /* On realise l'affectation de l'adresse memoire alloue par malloc  */ 
     char * string = (char *) malloc(sizeof(char));
     /* On verifie que toute allocation c'est bien passer */ 
     if(string==NULL){
          perror("malloc");
          return NULL;
     }
     char c;
     int i = 0;
     /* Tant que l'on a pas lu de caractere de retour a la ligne on continue la demande de saisie */
     while((c=getchar())!='\n'){
          /* Si le caractere lu n'est pas un espace*/
          if(c!=' '){
               /* On realloue l'addresse memoire du tableau de une case suplementaire */
               string = (char *) realloc(string, (i+1)*sizeof(char));
               /* On verifie que toute allocation c'est bien passer */ 
               if(string == NULL){
                    perror("realloc");
                    return NULL;
               }
               /* On ajoute notre caractere a notre tableau */
               *(string + i++) = c;
          }
          
     }
     /* On realloue au final notre tableau d'une case suplemtaire */
     string = (char *) realloc(string, (i+1)*sizeof(char));
     /* On verifie que toute allocation c'est bien passer */ 
     if(string==NULL){
          perror("realloc");
          return NULL;
     }
     /* On ajoute notre caractere \0 a notre tableau pour indiquer la fin*/
     *(string + i) = '\0';
     /* Finalement on retourne notre chaine de caracteres */
     return string;
}