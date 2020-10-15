// auteur: Michael Hauspie

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define PAS 5

char *** ligne_commande (int * flag, int *nb);
void libere (char ***t);
void affiche (char ***t);