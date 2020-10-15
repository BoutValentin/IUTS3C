.PHONY: clean

COMPILATEUR = gcc
FLAGOBJECT = -W -Werror -o 
PJNAME = mish  
SRCDIR = ./src/
OBJDIR = ./obj/
BINDIR = ./bin/
args=$(filter-out $@, $(MAKECMDGOALS))

all:
	echo "Veuillez verfier arg"
start: 
	.$(BINDIR)$(PJNAME) $(args)
build: $(BINDIR)$(PJNAME)


$(BINDIR)$(PJNAME): $(OBJDIR)main.o $(OBJDIR)affichage.o $(OBJDIR)ligne_commande.o $(OBJDIR)execute_ligne_command.o
	$(COMPILATEUR) $(FLAGOBJECT) $(BINDIR)$(PJNAME) $(OBJDIR)main.o $(OBJDIR)affichage.o $(OBJDIR)ligne_commande.o $(OBJDIR)execute_ligne_command.o

$(OBJDIR)main.o: $(SRCDIR)main.c
	$(COMPILATEUR) -c $(FLAGOBJECT) $(OBJDIR)main.o $(SRCDIR)main.c

$(OBJDIR)affichage.o: $(SRCDIR)affichage.c
	$(COMPILATEUR) -c $(FLAGOBJECT) $(OBJDIR)affichage.o $(SRCDIR)affichage.c

$(OBJDIR)ligne_commande.o: $(SRCDIR)ligne_commande.c
	$(COMPILATEUR) -c $(FLAGOBJECT) $(OBJDIR)ligne_commande.o $(SRCDIR)ligne_commande.c

$(OBJDIR)execute_ligne_command.o: $(SRCDIR)execute_ligne_command.c
	$(COMPILATEUR) -c $(FLAGOBJECT) $(OBJDIR)execute_ligne_command.o $(SRCDIR)execute_ligne_command.c

clean:
	rm -f $(OBJDIR)*.o