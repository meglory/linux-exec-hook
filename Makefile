
all:
	gcc -pipe -DDEBUG -g -shared -fPIC -D_REENTRANT exec-hook.c -o exec-hook.so -ldl -lrt

clean:
	rm -rf *.so *~