#include <stdio.h>
#include <stdlib.h>
char * saisie(){
     char * string = (char *) malloc(sizeof(char));
     char c;
     int i = 0;
     while((c=getchar())!='\n'){
          if(c!=' '){
          string = (char *) realloc(string, (i+1)*sizeof(char));
          *(string + i++) = c;

          }
          
     }
     string = (char *) realloc(string, (i+1)*sizeof(char));
     *(string + i) = '\0';

     return string;
}