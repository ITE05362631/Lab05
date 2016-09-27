ReceiveDataSocket:ReceiveDataSocket.o
	gcc -o ReceiveDataSocket ReceiveDataSocket.o

ReceiveDataSocket.o:ReceiveDataSocket.c
	gcc -c ReceiveDataSocket.c

clean:
	rm *.o
