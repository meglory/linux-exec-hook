all:
	gcc -shared -fPIC exec-hook.c -o exec-hook.so -ldl

clean:
	rm -rf *.so *~