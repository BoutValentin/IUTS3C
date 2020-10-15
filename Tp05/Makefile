.PHONY: clean

COMPILATEUR = gcc
FLAGOBJECT = -W -Werror -o 
PJNAME = wordCount  
SRCDIR = ./src/
OBJDIR = ./obj/
BINDIR = ./bin/


$(BINDIR)$(PJNAME): $(OBJDIR)main.o $(OBJDIR)traitement.o 
	$(COMPILATEUR) $(FLAGOBJECT) $(BINDIR)$(PJNAME) $(OBJDIR)main.o $(OBJDIR)traitement.o 

$(OBJDIR)main.o: $(SRCDIR)main.c
	$(COMPILATEUR) -c $(FLAGOBJECT) $(OBJDIR)main.o $(SRCDIR)main.c

$(OBJDIR)traitement.o: $(SRCDIR)traitement.c
	$(COMPILATEUR) -c $(FLAGOBJECT) $(OBJDIR)traitement.o $(SRCDIR)traitement.c

clean:
	rm -f $(OBJDIR)*.o