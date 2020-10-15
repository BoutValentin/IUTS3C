#include "./longeur.h"
#include <stdio.h>
char *mon_strcat(char *s1,const char *s2){
     int cpt = mon_strlen2(s1);
     printf("cpt : %d \n", cpt);
     int cpt2 = 0;
     while(cpt2<mon_strlen2(s2)){
          char copyChar = *(s2 + cpt2++); 
          
          *(s1 + cpt++) = copyChar;
     }

     *(s1+cpt) = '\0';

     return s1;
} 

/* char *mon_strcat(char *s1, const char *s2) {
    char *res = s1;
    int len = mon_strlen2(s1);
    int i;
    for (i = 0; i < mon_strlen2(s2); i++) {
        s1[len++] = s2[i];
        printf("%s\n", res);
    }

    s1[len] = '\0';
    printf("%s\n", res);
    return res;
} */
