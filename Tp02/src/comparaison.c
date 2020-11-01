#include "./longeur.h"

/* Comparaison des chaines de caracteres */
int mon_strcmp(const char * s1, const char *s2){

     int cpt = 0;
     /* Tant qu'on a des caracteres a lire dans les deux cotes */
     while(*(s1+cpt)&&*(s2+cpt)){
          /* Si le caractere de la chaine 1 est avant le caractere de la chaine deux a la meme position alors la chaine 1 est inferieur et cas contraire */
          if(*(s1+cpt)<*(s2+cpt)) return -1;
          else if(*(s1+cpt)>*(s2+cpt)) return 1;
          else{
               /* Sinon ils sont egales et on continuent la comparaison */
               cpt++;
          }
     }
     /* Si il etait egal juste la on compare les longeurs */
     if(mon_strlen2(s1)<mon_strlen2(s2)){
          return -1;
     }else if(mon_strlen2(s1)>mon_strlen2(s2))return 1;
     /* Sinon ils sont egals */
     return 0;
}

/* Comparaison par une chaine de caractere */
int mon_strcmp2(const char * s1, const char *s2, int n){
     /* Si le caractere demande est plus grand que l'une des deux chaines alors c'est une comparaison classique */
     if (n>mon_strlen2(s1) || n>mon_strlen2(s2)) return mon_strcmp(s1,s2);
     int cpt = 0;
     /* Sinon on compare caractere a caractere */
     while(cpt<n){
          if(*(s1+cpt)<*(s2+cpt)) return -1;
          else if(*(s1+cpt)>*(s2+cpt)) return 1;
          else{
               cpt++;
          }
     }
     return 0;
}