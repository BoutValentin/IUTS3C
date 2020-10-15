#include "./longeur.h"
#include <stdio.h>
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
     if(mon_strlen2(needle)>mon_strlen2(haystack)) return NULL;
     if(mon_strlen2(needle)==mon_strlen2(haystack) && *(haystack)!=*(needle)) return NULL;
     for(cpt1 = 0;*(haystack+cpt1);cpt1++ ){
          if((*(haystack+(cpt1))==*(needle+cpt2))){
               if((cpt1+mon_strlen2(needle))>mon_strlen2(haystack)) return NULL;
               for(cpt2=0;*(haystack+(cpt1+cpt2))&&*(needle+cpt2);cpt2++){
                    if(!(*(haystack+(cpt1+cpt2))==*(needle+cpt2))) break;
               }
               if(cpt2==mon_strlen2(needle)) return (haystack+(cpt1));
          }
     }
     return NULL;
}