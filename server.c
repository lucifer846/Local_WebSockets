#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>


int main(){


    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in sockAddrStruc;

    sockAddrStruc.sin_family = AF_INET;
    sockAddrStruc.sin_port = htons(9001);
    sockAddrStruc.sin_addr.s_addr = inet_addr("192.168.100.5");

    bind(serverSocket, (struct sockaddr *)&sockAddrStruc, sizeof(sockAddrStruc));

    char sBuffer[500] = {0};
    char rBuffer[500] = {0};

    listen(serverSocket, 100);
     

    int clientSocket = accept(serverSocket, NULL, NULL);
    printf("client connected\n");


    while (1){
     memset(sBuffer, 0, sizeof(sBuffer));
    printf("Enter Your Message: ");fgets(sBuffer, sizeof(sBuffer), stdin);
    send(clientSocket, sBuffer, sizeof(sBuffer), 0);
     memset(rBuffer, 0, sizeof(rBuffer));  // Clear buffer
    recv(clientSocket, rBuffer, sizeof(rBuffer), 0);
    printf("Client : %s", rBuffer);
    }

    // close(serverSocket);


    return EXIT_SUCCESS;
}

