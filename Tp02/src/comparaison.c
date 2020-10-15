#include "./longeur.h"
int mon_strcmp(const char * s1, const char *s2){

     int cpt = 0;
     while(*(s1+cpt)&&*(s2+cpt)){
          if(*(s1+cpt)<*(s2+cpt)) return -1;
          else if(*(s1+cpt)>*(s2+cpt)) return 1;
          else{
               cpt++;
          }
     }
     if(mon_strlen2(s1)<mon_strlen2(s2)){
          return -1;
     }else if(mon_strlen2(s1)>mon_strlen2(s2))return 1;
     return 0;
}

int mon_strcmp2(const char * s1, const char *s2, int n){
     if (n>mon_strlen2(s1) || n>mon_strlen2(s2)) return mon_strcmp(s1,s2);
     int cpt = 0;
     while(cpt<n){
          if(*(s1+cpt)<*(s2+cpt)) return -1;
          else if(*(s1+cpt)>*(s2+cpt)) return 0;
          else{
               cpt++;
          }
     }
     return 0;
}