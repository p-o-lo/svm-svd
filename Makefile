CPP=g++

LIBHDF5= /usr/include/hdf5/serial/
EIGEN= /home/paolo/PhD_Nice/codiciSVM/eigen/

COPT= -O3 -DNDEBUG -mavx -mfma -g -std=c++14 -Wall -I$(EIGEN)  -I$(LIBHDF5)
COPT= -O3 -DNDEBUG -Wall -g -std=c++11 -I$(EIGEN) -I$(LIBHDF5)

# COPT= -Wall -ggdb -std=c++11 -I$(EIGEN) -I$(LIBHDF5)
LIBS= -lgsl -lblas -lhdf5 -llapack #-larpack -lgslcblas -lgfortran -fopenmp 
PHDF5=/usr/lib/x86_64-linux-gnu/hdf5/serial

CPPFLAGS=$(COPT)

OBJECTS= main.o inputData.o coordinates.o funcToFindRoot.o basis.o akpot.o

OBJECTS_1= change4Body.o inputData.o coordinates.o basisEV.o akpot.o



#---------------- Main program --------------------------------------
svmThree: ${OBJECTS} Makefile
	  ${CPP} -L${PHDF5} -o $@ ${OBJECTS} ${LIBS}  

#---------------- Main program --------------------------------------
change4Body: ${OBJECTS_1} Makefile
	  ${CPP} -L${PHDF5} ${LIBS}  -o $@ ${OBJECTS_1}
#---------------- Objects -------------------------------------------
change4Body.o: change4Body.cc 
	${CPP} ${CPPFLAGS} -c  $<
main.o: main.cc 
	${CPP} ${CPPFLAGS} -c  $<
inputData.o: inputData.cc inputData.h
	${CPP} ${CPPFLAGS} -c  $<
coordinates.o: coordinates.cc coordinates.h
	${CPP} ${CPPFLAGS} -c  $<
funcToFindRoot.o: funcToFindRoot.cc funcToFindRoot.h
	${CPP} ${CPPFLAGS} -c  $<
basis.o: basis.cc basis.h
	${CPP} ${CPPFLAGS} -c  $<
akpot.o: akpot.f  
	gfortran -c $<
#----------------- Clean --------------------------------------------
clean:
	@rm *.o svmThree change4Body

