#include <stdio.h>

void affiche_prompt(){     
     /* Permet d'afficher ce que contient le buffer et de le 'nettoyer' */
     fflush(stdout);
     /* On affiche notre afficage de notre prompt ou plus precisement on met dans le buffer*/ 
     printf("mich$  ");
     /* Permet d'afficher ce que contient le buffer et de le 'nettoyer' */
     fflush(stdout);
}