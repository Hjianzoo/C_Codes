objects=calc.o framework.o
calc:$(objects)
	gcc -o calc $(objects)
calc.o:calc.c calc.h
	gcc -c calc.c
framework.o:framework.c calc.h
	gcc -c framework.c

clean:
	-rm *.o calc