
#include <stdio.h>

void printTaille(char *s,int size){
     printf("taille %s: %d octets \n",s,size);
     return;
}

void printPosition(char *s, int size) {
     printf("position %s: %p \n",s, size);
}

void printALL(){
      char c ;
     int i;
     float f;
     double d;
     int t[10];
     char *s = "abc";
     struct point
     {
          int x;
          int y;
     } p;

     printTaille("char", sizeof(c));
     printTaille("int", sizeof(i));
     printTaille("float", sizeof(f));
     printTaille("double", sizeof(d));
     printTaille("int[10]", sizeof(t));
     printTaille("s", sizeof(s));
     printTaille("struct point", sizeof(p));

     printPosition("c", &c);
     printPosition("i", &i);
     printPosition("f", &f);
     printPosition("d", &d);
     printPosition("t", &t);
     printPosition("s", &s);
     printPosition("p", &p);
}