#include "./ManipStruc.h"
#include <math.h>
#include <stdio.h>
int distance(point p1, point p2){
     return sqrt(pow((p2.x - p1.x),2)+pow((p2.y - p1.y),2));
}

int longueur(point segments[],int nombreSegments){
     int somme = 0;
     int i =0;
     for(i=0;i<nombreSegments;i++){
          if(i+1<nombreSegments){
               somme+= distance(segments[i],segments[i+1]);
          }
     }
     return somme;    
}

int plusProche(point reference, point segments[], int nbseg){
     int i = 0;
     int posPlusProche = 0;
     if(nbseg<2)return posPlusProche;
     int plusProche = distance(segments[i],reference);
     while(i<nbseg){
          if(plusProche>distance(segments[i++], reference)){
               posPlusProche = i;
          }
     }
     return posPlusProche; 
}

void testManipStruc(){

     point p1 = {0,0};
     point p2 = {5,5};
     point p3 = {7,-78};
     point p4 = {9, 9};
     point segments[] = {p1,p2,p3};
     printf("distance p1 p2: %d \n", distance(p1,p2));
     printf("distance p2 p3: %d \n", distance(p2,p3));
     printf("longeurs segment p1 p2 p3: %d \n", longueur(segments,3));
     printf("distance p1 p4: %d \n", distance(p1,p4));
     printf("distance p2 p4: %d \n", distance(p2,p4));
     printf("distance p3 p4: %d \n", distance(p3,p4));
     printf("plus proche point de p4: %d \n",plusProche(p4,segments,3));

}


