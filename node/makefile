objects=node.o
node:$(objects)
	gcc -o node $(objects) 
node.o:node.c node.h
	gcc -c node.c
.PHONY:clean
clean:
	-rm node *.o