#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

/* Fonction permettant de mettre a null chaque case d'u tableau */
void fillArray(char * array, int size){
     int i = 0;
     while(i<size) array[i++] = '\0';
}

int traiter(int f, int *car, int *mot, int *lig){
     
     /* On declare un buffer de 80 char */
     char buffer[80];
     /* On initialiase ce buffer a null */
     fillArray(buffer, 80);
     /* Initialisation des variables de compte */
     int numberRead = 0;
     int wasWhiteSpace = 0;
     /* Tant que la fin du fichier n'est pas atteinte */
     while(numberRead = read(f, buffer, 80)){
          /* Dans le cas ou on a un retour de -1 un probleme est survenu et on arrete l'execution du programme */
          if(numberRead==-1)return -1;
          /* Initialisation de nos variables de compte pour chaque buffer */
          int carCount = 0;
          int wordCount = 0;
          int ligCount = 0;
          int idx = 0;
          /* Tant qu'on a des caracteres dans le buffer */
          while(buffer[carCount]){
               /* Si le caractere lu est un separateur */
               if(isspace(buffer[carCount])){
                    /* Si on a lu un retour a la ligne */
                    if(buffer[carCount]=='\n'){
                         /* Si on a lu au moins un caractere et que le caractere precedent n'etait pas un espace alors on ajoute un mot */
                         if(carCount>=1 && !isspace(buffer[carCount-1])) wordCount++;
                         /* Dans le cas ou a lu un seul caractere il reste la possibilite que nous avions un espace a la ligne d'avant */
                         else if(!wasWhiteSpace && carCount==0) wordCount++;
                         /* Dans tout les on ajoute une ligne */
                         ligCount++;
                    }else if(carCount>=1 && !isspace(buffer[carCount -1])) {
                         /* Si ce n'etait pas un retour a la ligne et Si on a lu au moins un caractere et que le caractere precedent n'etait pas un espace alors on ajoute un mot */
                         wordCount++;
                    }else if(!wasWhiteSpace && carCount==0) {
                         /* Dans le cas ou a lu un seul caractere il reste la possibilite que nous avions un espace a la ligne d'avant */
                         wordCount++;
                    }
               }
               /* Dans tout les cas un caracteres a etait lu */
               carCount++;
          }
          /* Si la derniere case lu etait un sepateur alors on passe le wasWhiteSpace a 1 indiquant qu'il est probable qu'un nouveau mot commence*/
          if(isspace(buffer[carCount -1])) wasWhiteSpace = 1;
          else wasWhiteSpace = 0;
          /* Sinon on indique que c'etait une lettre classique */
          /* On ajoute une derniere ligne lu qui n'est jamais compter*/
          ligCount++;
          if(carCount>=1 && !isspace(buffer[carCount -1])) wordCount++;
          /* On ajouute au valeur pointer par ces pointeurs ce qu'on vient de lire*/
          *mot += wordCount;
          *car = *car + numberRead ;
          *lig += ligCount;
          /* On reset notre buffer a null */
          fillArray(buffer, 80);
     };
     /* On ferme le file descriptor*/
     close(f);
     /* Tout c'est bien passer donc on return 0 */
     return 0;
}

/* Fonction d'affichage du message d'erreur */
void printError(){
     printf("You are miss using this line of command: \ngeneral form: wordCount [-cwl] [fichier]* \n Description: \t  Print newline, word, and byte counts for each FILEParameter :\n-c\n \t print the byte/character count \n-w \n\t print the word count \n-l \n\t print the newlignes count \n");
}