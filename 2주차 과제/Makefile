cc = gcc
target=StarWars_exe
objects = main.o Count.o Arithmetic.o

$(target) : $(objects)
	$(cc) -o $(target) $(objects)

$(objects) : Header.h

.PHONY : clean
clean :
	rm $(target) $(objects)
