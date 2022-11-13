
all:
	gcc -shared exec-hook.c -o exec-hook.so -Wall -Wfatal-errors -fPIC -g -ldl

clean:
	rm -rf *.so *~