#include <stdio.h>
#include <stdlib.h>
int mon_strlen2(const char *s){
     int cpt = 0;
     while(*(s + cpt))cpt++;
     return cpt;     
     /*return mon_strlen(s);*/
}
char * miroir(const char *s){
     char *inverse = malloc(mon_strlen2(s)*sizeof(char));
     int cpt = mon_strlen2(s) -1;
     int cpt2 = 0;
     while(cpt>=0){
          *(inverse + cpt2++) = *(s + cpt);
          cpt--;
     }
     inverse[cpt2] ='\0';
     return inverse;
}