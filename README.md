# Socket Communication - Client (Windows) and Server (Linux)

This project demonstrates a simple client-server communication setup where the client (running on Windows) connects to a server (running on Linux) using TCP sockets. The client sends and receives messages from the server in a continuous loop.

## Files

1. **client.c** - A Windows-based client program that connects to the server and communicates via sockets.
2. **server.c** - A Linux-based server program that listens for incoming connections and communicates with the client.

## Prerequisites

- **For the client**: Windows operating system with `WinSock2` library support.
- **For the server**: Linux operating system with standard socket libraries (e.g., `sys/socket.h`, `netinet/in.h`, `arpa/inet.h`).

### Requirements:
- **Windows (Client)**: Requires Visual Studio or any C compiler that supports the WinSock2 library.
- **Linux (Server)**: Any standard C compiler (e.g., `gcc`).

## Compilation and Execution

### 1. **Client (Windows)**

#### Steps to compile:
1. Open the **Developer Command Prompt for Visual Studio**.
2. Navigate to the directory where `client.c` is located.
3. Run the following command to compile the client:

```bash
cl client.c /link Ws2_32.lib
