.PHONY: all
all:
	cp ./csapp.h /usr/include;	\
	gcc -c -fPIC -o csapp.o csapp.c;	\
	gcc --shared -o libcsapp.so csapp.o -lpthread;	\
	cp libcsapp.so /usr/local/lib;	\
	ldconfig /usr/local/bin;	\
	gcc -o test test.c -lcsapp;	\
	./test && cat test.txt

.PHONY: clean
clean:
	rm -rf csapp.o libcsapp.so test test.txt
