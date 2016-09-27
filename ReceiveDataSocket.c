#include<stdio.h>
#include<string.h>   
#include<sys/socket.h>
#include<arpa/inet.h> 
#include<netdb.h>

int main(int argc , char *argv[])
{
    int socket_desc;
    struct sockaddr_in server;
    char *message , server_reply[2000];
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }

    char *hostname = "www.mcu.edu.tw";
    char ip[100];
    struct hostent *he;
    struct in_addr **addr_list;
    int i;
    if ( (he = gethostbyname( hostname ) ) == NULL)
    {
        herror("gethostbyname");
        return 1;
    }
    addr_list = (struct in_addr **) he->h_addr_list;
    for(i = 0; addr_list[i] != NULL; i++)
    {
        strcpy(ip , inet_ntoa(*addr_list[i]) );
    }

    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons( 80 );
    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("connect error");
        return 1;
    }
    puts("Connected\n");
    message = "GET / HTTP/1.1\r\n\r\n";
    if( send(socket_desc , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }
    puts("Data Send\n");
    if( recv(socket_desc, server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }
    puts("Reply received\n");
    puts(server_reply);
    return 0;
    }