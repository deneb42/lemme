#Le compilateur c++ utilisé par le Makefile. Par défaut le compilateur est g++. Si vous en changez, merci de vous assurer que votre code compile aussi avec g++.
CPP = g++

PROGPATH = ../bin/
PROGNAME = occurences

FILES = lemme.o main.o

#Les options du compilateur c++
#Pensez à mettre -g et enlever -O3 pour le debug!
#CPPOPT = -O3 -Wall
CPPOPT = -Wextra -pedantic -g -Wall

#Les options de l'éditeur de lien
LNKOPT = -g

all: occurences

run: test

test: 
	$(PROGPATH)$(PROGNAME)
	
occurences: $(FILES)
	$(CPP) $(LNKOPT) $(FILES) -o $(PROGPATH)$(PROGNAME)

%.o : %.cpp
	$(CPP) -c $(CPPOPT) $< 
	
mrproper: clean
	rm $(PROGPATH)$(PROGNAME)

clean:
	rm $(FILES)
