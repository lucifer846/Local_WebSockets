#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WinSock2.h>
#include <Ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#pragma warning(push)
#pragma warning(disable : 4996)

// WSAStartup(), socket(), connect(), send(), recv()

int main() {

	// winsock initialization
	WSADATA wsaStructure;
	int result = WSAStartup(MAKEWORD(2, 2), &wsaStructure); //changed WORD (from MAKEWORD(2,2))
	if (result != 0) {
		printf("[!] winsock initialization failed\n");
	}

	// socket()
	SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocket == INVALID_SOCKET) {
		printf("Socket creation failed\n");
		WSACleanup();
		return EXIT_FAILURE;
	}



	// connect() and structure passed as argument in connect()
	struct sockaddr_in clientAddr;
	clientAddr.sin_family = AF_INET;
	clientAddr.sin_port = htons(9001);
	clientAddr.sin_addr.s_addr = inet_addr("192.168.100.5");
	if (connect(clientSocket, (struct sockaddr*)&clientAddr, sizeof(clientAddr)) == SOCKET_ERROR) {
		printf("Connection failed\n");
		closesocket(clientSocket);
		WSACleanup();
		return EXIT_FAILURE;
	}
	printf("server connected\n");

	char sBuffer[500] = {0};
	char rBuffer[500] = {0};
		
	while (1) {
		//recv()
		memset(rBuffer, 0, sizeof(rBuffer));  // Clear buffer
		recv(clientSocket, rBuffer, sizeof(rBuffer), 0);
		printf("Server: %s", rBuffer);
		memset(sBuffer, 0, sizeof(sBuffer));
		//send()
		printf("Enter Your Message: ");fgets(sBuffer, sizeof(sBuffer), stdin);
		send(clientSocket, sBuffer, sizeof(sBuffer), 0);
	}
	//closesocket(clientSocket);

	//WSACleanup();

	return EXIT_SUCCESS;
}
#pragma warning(pop)