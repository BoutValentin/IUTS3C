#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

void fillArray(char * array, int size){
     int i = 0;
     while(i<size) array[i++] = '\0';
}

int traiter(int f, int *car, int *mot, int *lig){
     
     char buffer[80];
     fillArray(buffer, 80);
     int cpt = 0;
     int numberRead = 0;
     int wasWhiteSpace = 0;
     int wasBn = 0;
     int numberSpace = 0;
     while(numberRead = read(f, buffer, 80)){
          if(numberRead==-1)return -1;
          int carCount = 0;
          int wordCount = 0;
          int ligCount = 0;
          int idx = 0;
          while(buffer[carCount]){
               if(isspace(buffer[carCount])){
                    if(buffer[carCount]=='\n'){
                         if(carCount>=1 && !isspace(buffer[carCount-1])) wordCount++;
                         else if(!wasWhiteSpace && carCount==0) wordCount++;
                         ligCount++;
                    }else if(carCount>=1 && !isspace(buffer[carCount -1])) {
                         wordCount++;

                    }else if(!wasWhiteSpace && carCount==0) {
                         wordCount++;
                    }
                    numberSpace++;
               }
               carCount ++;
          }
          if(isspace(buffer[carCount -1])) wasWhiteSpace = 1;
          else wasWhiteSpace = 0;
          *mot += wordCount;
          *car = *car + numberRead ;
          *lig += ligCount;
          fillArray(buffer, 80);


     };
     close(f);
     return 0;
}

void printError(){
     printf("You are miss using this line of command: \ngeneral form: wordCount [-cwl] [fichier]* \n Description: \t  Print newline, word, and byte counts for each FILEParameter :\n-c\n \t print the byte/character count \n-w \n\t print the word count \n-l \n\t print the newlignes count \n");
}