cc = gcc
target = fmt
objects = main.o Output.o String_Manipulation.o

$(target): $(objects)
	$(cc) -o $(target) $(objects)

$(objects): Header.h

.PHONY : clean
clean :
	rm $(target) $(objects)
