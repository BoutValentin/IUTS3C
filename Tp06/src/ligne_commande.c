// auteur: Michael Hauspie

#include "ligne_commande.h"

void affiche (char ***t) {
   if(t==NULL){
        printf("Null tab \n");
        return;
   }
   int i = 0, j;
   while (t[i] != NULL) {
      printf ("---> commande no %d\n", i);
      j = 0;
      while (t[i][j] != NULL) {
         printf("      argv[%d] = %s\n", j,t[i][j]);
         j++;
      }
      i++;
   }
}


void libere (char ***t) {
   int i = 0, j;

   while (t[i] != NULL) {
      j = 0;
      while (t[i][j] != NULL) {
         free(t[i][j]);
         j++;
      }
      free(t[i]);
      i++;
   }
   free(t);
}

/**********************************************************************
   Saisie d'une ligne de taille quelconque terminee par un "newline" 
   retourne NULL en cas d'erreur
**********************************************************************/
char * saisie_ligne_commande() {
   int t = PAS, i = 0;
   char *ligne = (char*) malloc (sizeof(char) * t);
   char *tmp;
   int n = 0;
   while ((n = read(0, ligne+i, sizeof(char)*PAS)) > 0) {
      if (n == PAS && *(ligne+i+PAS-1) != '\n') {
         t = t + PAS;
         tmp = (char *) realloc (ligne, sizeof(char) * t);
         if (tmp == NULL) {
            perror("mish -- erreur lecture de la ligne de commande");
            free(ligne);
            return NULL;
         }
         ligne = tmp;
         i = i + n;
      }
      else {
         *(ligne+i+n-1) = '\0';
         return ligne;
      }      
   }
   free(ligne);
   return NULL;
}

/**********************************************************************
   Separateur
**********************************************************************/
int separateur (int c) {
   return c == '|' || c == '&' || c == '\0';
}

/**********************************************************************
   Analyse ligne commande
**********************************************************************/
char *** ligne_commande (int * flag, int * nb) {
   char * ligne = saisie_ligne_commande();
   char *** tab, ***tmp_tab, **tmp_mot, *tmp_car;
   int i_tab = 0, t_tab = PAS, t_mot = PAS, t_car = PAS;
   int i = 0, i_mot, i_car;

   *nb = 0;

   if (ligne == NULL) return NULL;
   while (ligne[i] != '\0' && (ligne[i] == ' ' || ligne[i] == '\t')) i++; 
   if (ligne[i] == '\0') {free(ligne); return NULL;} 
   tab = (char ***) malloc (PAS * sizeof(char**));
   if (tab == NULL ) return NULL;
   while (ligne [i] != '\0' && ligne [i] != '&') {
      if (i_tab == t_tab -1) {
         t_tab += PAS;
         tmp_tab = (char ***) realloc (tab, sizeof(char**)*t_tab);
         if (tmp_tab == NULL) {
            tab[i_tab] = NULL;
            free(ligne);
            *flag = -1;
            return tab;
	 }
         tab = tmp_tab;
      }
      if ((tab[i_tab] = (char**) malloc (sizeof(char *) * PAS)) == NULL) {
         *flag = -1;
         free(ligne);
         return tab;
      }
         
      t_mot = PAS;
      i_mot = 0;
      while (!separateur(ligne [i])) {
         if (i_mot == t_mot -1) {
            t_mot = t_mot+PAS;
	    /****/
            tmp_mot =(char **) realloc (tab[i_tab], sizeof(char*) * t_mot);
            if (tmp_mot == NULL) {
               tab[i_tab][i_mot] = NULL;
               tab[i_tab+1] = NULL;
               free(ligne);
               *flag = -1; 
               return tab;
	    }
            tab[i_tab] = tmp_mot;
	 }
         if ((tab[i_tab][i_mot] = (char *) malloc (sizeof(char) * PAS)) == NULL) {
            tab[i_tab+1] = NULL;
            *flag = -1;
            free(ligne);
            return tab;
	 }
         i_car = 0;
         while (!isspace (ligne[i]) && !separateur(ligne[i])){
            if (i_car == t_car -1) {
               t_car = t_car+PAS;
               tmp_car = (char *) realloc (tab[i_tab][i_mot],sizeof(char) * t_car);
               if (tmp_car == NULL) {
                  tab[i_tab][i_mot][i_car] = '\0';
                  tab[i_tab][i_mot+1] = NULL;
                  tab[i_tab+1] = NULL;
                  *flag = -1;
                  free(ligne);
                  return tab;
	       }
               tab[i_tab][i_mot] = tmp_car; 
	    }
            tab[i_tab][i_mot][i_car] = ligne[i];
            i++;
            i_car++;
	 }
         tab[i_tab][i_mot][i_car] = '\0';
         while (isspace(ligne[i])) i++;
         i_mot++;  
      }
      tab[i_tab][i_mot] = NULL;
      i_tab++;
      if (ligne [i] == '|') {
         i ++;
         while (isspace(ligne[i])) i++;
         if (separateur(ligne[i])) {
            fprintf(stderr, "mish -- erreur de syntaxe\n");
            free(ligne);
            return NULL;
	 } 
      }
   }
   tab [i_tab] = NULL;
   if (ligne[i] == '\0') *flag = 0;
   else *flag = 1;
   free(ligne);
   *nb = i_tab;
   return tab;
}
                
