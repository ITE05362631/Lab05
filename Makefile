SocketConnect:SocketConnect.o
	gcc -o SocketConnect SocketConnect.o

SocketConnect.o:SocketConnect.c
	gcc -c SocketConnect.c

clean:
	rm *.o
