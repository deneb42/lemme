#|  C++ TP2    makefile             |
#|                                  |
#|  by :deneb                       |
#|  last modif : 21/12/12           |
#/__________________________________/


GCC=g++
LFLAGS = -g
CFLAGS = -Wall -Wextra -pedantic -g 
#-O2

# Name of the files (more .o)
OBJS = main.o plan.o station.o 
# Path where the bin will be
PGM_PATH = ../bin/
PGM_NAME = metro

# For the generic utilisation, 
# DO NOT TOUCH ANYTHING UNDER THIS LINE !!!
# ___________________________________________

all : $(OBJS)
	$(GCC) -o $(PGM_PATH)$(PGM_NAME) $(LFALGS) $(OBJS)  
	
# generic method for all the .o
%.o : %.cpp
	$(GCC) $(CFLAGS) -c $< 

run :
	$(PGM_PATH)$(PGM)

clean :
	-rm *.o *~
	
mrproper : clean
	-rm $(PGM_PATH)$(PGM_NAME)
