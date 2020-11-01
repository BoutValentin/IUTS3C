#include "./longeur.h"
#include <stdio.h>

/* Function retournant l'adresse du caractere si il est contenu sinon null*/
char *mon_strchr(char *s, int c){
     int cpt = 0;
     while(cpt<mon_strlen2(s)&&*(s+cpt)){
          if(*(s+cpt)==c) return (s+cpt);
          cpt++; 
     }
     return NULL;
}

char *mon_strstr(char *haystack, char *needle){
     int cpt1 = 0, cpt2=0;
     /* Si la chaine deux recherche est plus grande alors on retourne null */
     if(mon_strlen2(needle)>mon_strlen2(haystack)) return NULL;
     /* Si Les deux chaines on la meme longeur mais le premiere caractere differe on sait que cest faux et retourne null */
     if(mon_strlen2(needle)==mon_strlen2(haystack) && *(haystack)!=*(needle)) return NULL;
     /* On parcours notre premiere chaine  */
     for(cpt1 = 0;*(haystack+cpt1);cpt1++ ){
          /* Si les deux caracteres a la meme position sont egale alors on commence notre recher de needle*/
          if((*(haystack+(cpt1))==*(needle+cpt2))){
               /* Si le nombre de caractere a lire est inferieurs a la chaine a trouver alors on ne peut plus trouvers cette chaine */
               if((cpt1+mon_strlen2(needle))>mon_strlen2(haystack)) return NULL;
               /* On parcours maintenant notre deuxieme chaine */
               for(cpt2=0;*(haystack+(cpt1+cpt2))&&*(needle+cpt2);cpt2++){
                    /* si les deux caracteres sont differents alors on arrete notre boucle*/
                    if(!(*(haystack+(cpt1+cpt2))==*(needle+cpt2))) break;
               }
               /* Finalement si notre compteur 2 a parcouru toute la needle alors on return la ou on sait arreter dans l'haystack*/
               if(cpt2==mon_strlen2(needle)) return (haystack+(cpt1));
          }
     }
     /* Sinon on retourne null */
     return NULL;
}