#include "affichage.h"
#include "execute_ligne_command.h"
#define TRUE 1
#define FALSE 0
int main(int argc, char const **argv){

     /* While True*/
     while(1){
          affiche_prompt();
          execute_ligne_commande();
     } 
     
     return 0;
}