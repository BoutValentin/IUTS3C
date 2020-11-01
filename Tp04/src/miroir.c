#include <stdio.h>
#include <stdlib.h>

/* Fonction recuperant la taille d'unce chaine de caractere */
int mon_strlen2(const char *s){
     /* On initialise notre compteur */ 
     int cpt = 0;
     /* Tant qu'on a pas lu le caractere \0 */
     while(*(s + cpt))cpt++;
     /* On retourne notre compteur lu */
     return cpt;     
}
/* Fonction retournant le miroir d'une chaine de caractere */ 
char * miroir(const char *s){
     /* On alloue un tableau de caractere de la taille de notre chaine passer en parametre */
     char *inverse = malloc(mon_strlen2(s)*sizeof(char));
     if(inverse==NULL){
          perror("malloc");
          return NULL;
     }
     /* ON recupere la longeur de notre chaine*/
     int cpt = mon_strlen2(s) -1;
     int cpt2 = 0;
     /* Tant que notre compteur inverser est superieur a zero */
     while(cpt>=0){
          /* On stocke dans notre nouveaux tableau le caractere de la chaine de caractere originelle*/ 
          *(inverse + cpt2++) = *(s + cpt);
          cpt--;
     }
     /* On ajoute a la fin le caractere de marqueur de fin */
     inverse[cpt2] ='\0';
     /* On retourne notre chaine de caractere inverse */
     return inverse;
}