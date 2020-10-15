.PHONY: clean

COMPILATEUR = gcc
FLAGOBJECT = -ansi -pedantic -W -o 
PJNAME = tp04Exec
SRCDIR = ./src/
OBJDIR = ./obj/
BINDIR = ./bin/

$(BINDIR)$(PJNAME): $(OBJDIR)main.o $(OBJDIR)miroir.o $(OBJDIR)saisie.o
	$(COMPILATEUR) $(FLAGOBJECT) $(BINDIR)$(PJNAME) $(OBJDIR)main.o $(OBJDIR)miroir.o $(OBJDIR)saisie.o

$(OBJDIR)main.o: $(SRCDIR)main.c $(OBJDIR)miroir.o
	$(COMPILATEUR) -c $(FLAGOBJECT) $(OBJDIR)main.o $(SRCDIR)main.c

$(OBJDIR)miroir.o: $(SRCDIR)miroir.c $(SRCDIR)miroir.h
	$(COMPILATEUR) -c $(FLAGOBJECT) $(OBJDIR)miroir.o $(SRCDIR)miroir.c

$(OBJDIR)saisie.o: $(SRCDIR)saisie.c $(SRCDIR)saisie.h
	$(COMPILATEUR) -c $(FLAGOBJECT) $(OBJDIR)saisie.o $(SRCDIR)saisie.c
clean:
	rm -f $(OBJDIR)*.o