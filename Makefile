
all:
	gcc -Wall -pipe -DDEBUG -g -D_GNU_SOURCE -shared -fPIC -D_REENTRANT exec-hook.c -o exec-hook.so -ldl -lrt

clean:
	rm -rf *.so *~