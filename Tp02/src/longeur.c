
/* Deux fonctions realisant la meme chose mais avec une notation differente */

int mon_strlen(char s[]){
     int cpt = 0;
     while(s[cpt])cpt++;
     return cpt;
}

int mon_strlen2(const char *s){
     int cpt = 0;
     while(*(s + cpt))cpt++;
     return cpt;     
}
