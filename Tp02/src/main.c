#include <stdio.h>
#include "./longeur.h"
#include "./comparaison.h"
#include "./concatenation.h"
#include "./research.h"
int main(int argc, char **argv){

     char s[] = "salut";
     char *s2 = "coucou les programmeurs";
     char s3[] = "salut0";
     char s4[11];
     int i = 0;
     for(i=0;s[i];i++){
          s4[i] = s[i];
     }
     while(s4[i])s4[i++]='\0';
     
     printf("Taille de %s: %d\n", s, mon_strlen(s));
     printf("Taille de %s: %d\n", s2, mon_strlen2(s2));
     printf("Comparaison de %s et %s: %d\n", s, s, mon_strcmp(s,s));
     printf("Comparaison de %s et %s: %d\n", s,s2, mon_strcmp(s,s2));
     printf("Comparaison de %s et %s: %d\n", s,s3, mon_strcmp(s,s3));
     printf("Comparaison de %s et %s: %d\n", s,s3, mon_strcmp2(s,s3,5));
     printf("Concatenation de %s et %s: %s\n", s4, "salut", mon_strcat(s4,"salut"));
     printf("Premiere occurence de %c dans %s: %d\n", 'w', s, mon_strchr(s,'w'));
     printf("Premiere occurence de %s dans %s: %d\n", "tot", s, mon_strstr(s,"tot"));
     return 0;
}