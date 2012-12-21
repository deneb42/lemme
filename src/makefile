#|  C++ TP2    makefile             |
#|                                  |
#|  by :deneb                       |
#|  last modif : 21/12/12           |
#/__________________________________/


INC_PATH = 
LIB_PATH = 
LIBRARY = -g
CFLAGS = -Wall -Wextra -pedantic -g 
#-O2
LDFALGS = $(LIB_PATH) $(LIBRARY)
GCC=g++

# Name of the files (more .o)
OBJS = main.o
# Path where the bin will be
PGM_PATH = ./
PGM_NAME = metro

# For the generic utilisation, 
# DO NOT TOUCH ANYTHING UNDER THIS LINE !!!
# ___________________________________________

# $(OBJS:.o=_client.o ) 
all : 
	$(GCC) -o $(PGM_PATH)$(PGM_NAME) $(OBJS) $(LDFALGS) 
	
# generic method for all the .o
%.o : %.c
	$(GCC) $(CFLAGS) $(INC_PATH) -c $< 

run :
	$(PGM_PATH)$(PGM)

clean :
	-rm *.o *~
	
mrproper : clean
	-rm $(PGM_PATH)$(PGM_NAME)
