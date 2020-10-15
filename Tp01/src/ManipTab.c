#include <stdio.h>

void affiche(int liste[], int taille){
     int i = 0;
     while(i<taille){
          printf("%d ;",liste[i++]);
     }
     printf("\n");
}

int somme(int liste[], int taille){
     int i =0;
     int somme = 0;
     while(i<taille) somme+=liste[i++];
     return somme;
}

void recopie(int src[],int dest[],int taille){
     int i= 0;
     while(i<taille){
          dest[i++] = src[i];
     }
}
void testManipTab(){
     
     int tab[] = {2,8,7,3,10};
     affiche(tab, sizeof tab / sizeof *tab);
     printf("somme : %d \n", somme(tab, sizeof tab / sizeof *tab));
     int tab2[5];
     recopie(tab,tab2,5);
     affiche(tab2,sizeof tab2 / sizeof *tab2);
}


