.PHONY: clean

COMPILATEUR = gcc
FLAGOBJECT = -ansi -pedantic -W -o 
PJNAME = tp01Exec
SRCDIR = ./src/
OBJDIR = ./obj/
BINDIR = ./bin/

$(BINDIR)$(PJNAME): $(OBJDIR)main.o
	$(COMPILATEUR) $(FLAGOBJECT) $(BINDIR)$(PJNAME) $(OBJDIR)Exercice1.o $(OBJDIR)ManipTab.o $(OBJDIR)ManipStruc.o -lm $(OBJDIR)main.o

$(OBJDIR)main.o: $(OBJDIR)Exercice1.o $(SRCDIR)main.c $(OBJDIR)ManipTab.o $(OBJDIR)ManipStruc.o
	$(COMPILATEUR) -c $(FLAGOBJECT) $(OBJDIR)main.o $(SRCDIR)main.c

$(OBJDIR)Exercice1.o: $(SRCDIR)Exercice1.c
	$(COMPILATEUR) -c $(FLAGOBJECT)  $(OBJDIR)Exercice1.o $(SRCDIR)Exercice1.c

$(OBJDIR)ManipTab.o: $(SRCDIR)ManipTab.c
	$(COMPILATEUR) -c $(FLAGOBJECT)  $(OBJDIR)ManipTab.o $(SRCDIR)ManipTab.c

$(OBJDIR)ManipStruc.o: $(SRCDIR)ManipStruc.c
	$(COMPILATEUR) -c $(FLAGOBJECT)  $(OBJDIR)ManipStruc.o $(SRCDIR)ManipStruc.c 
clean:
	rm -f $(OBJDIR)*.o