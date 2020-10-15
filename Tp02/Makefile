.PHONY: clean

COMPILATEUR = gcc
FLAGOBJECT = -ansi -pedantic -W -o 
PJNAME = tp02Exec
SRCDIR = ./src/
OBJDIR = ./obj/
BINDIR = ./bin/

$(BINDIR)$(PJNAME): $(OBJDIR)main.o $(OBJDIR)longeur.o $(OBJDIR)comparaison.o $(OBJDIR)concatenation.o $(OBJDIR)research.o
	$(COMPILATEUR) $(FLAGOBJECT) $(BINDIR)$(PJNAME) $(OBJDIR)main.o $(OBJDIR)longeur.o $(OBJDIR)comparaison.o $(OBJDIR)concatenation.o $(OBJDIR)research.o

$(OBJDIR)main.o: $(SRCDIR)main.c 
	$(COMPILATEUR) -c $(FLAGOBJECT) $(OBJDIR)main.o $(SRCDIR)main.c

$(OBJDIR)longeur.o: $(SRCDIR)longeur.c $(SRCDIR)longeur.h
	$(COMPILATEUR) -c $(FLAGOBJECT) $(OBJDIR)longeur.o $(SRCDIR)longeur.c

$(OBJDIR)comparaison.o: $(SRCDIR)comparaison.c $(SRCDIR)comparaison.h
	$(COMPILATEUR) -c $(FLAGOBJECT) $(OBJDIR)comparaison.o $(SRCDIR)comparaison.c

$(OBJDIR)concatenation.o: $(SRCDIR)concatenation.c $(SRCDIR)concatenation.h
	$(COMPILATEUR) -c $(FLAGOBJECT) $(OBJDIR)concatenation.o $(SRCDIR)concatenation.c

$(OBJDIR)research.o: $(SRCDIR)research.c $(SRCDIR)research.h
	$(COMPILATEUR) -c $(FLAGOBJECT) $(OBJDIR)research.o $(SRCDIR)research.c
clean:
	rm -f $(OBJDIR)*.o