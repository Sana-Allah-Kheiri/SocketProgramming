#include <iostream>
#include <winsock2.h>

using namespace std;

int main()
{

    char message[9999] {"HTTP/1.1 200 OK\nContent-length: 47\nContent-Type: text/html\n\n<html><body><H1>Hi Sasan Ace Welcome</H1></body></html>""HTTP/1.1 200 OK\nContent-length: 47\nContent-Type: text/html\n\n<html><body><H1>Learning Socket Programming</H1></body></html>"};

    WSADATA WSAData;

    SOCKET server, client;

    SOCKADDR_IN serverAddr, clientAddr;

    int msg_len;

    WSAStartup(MAKEWORD(2,0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // initializing feauters of server socket

    serverAddr.sin_addr.s_addr = INADDR_ANY; // connecting to all network interfaces such as wifi or lan
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);

    bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
    listen(server, 0);

    cout << "Listening for incoming connections..." << endl;

    char buffer[1024];
    int clientAddrSize = sizeof(clientAddr);
    if((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
    {
        cout << "Client connected!" << endl;
        recv(client, buffer, sizeof(buffer), 0);
        cout << "Client says: " << buffer << endl;
        memset(buffer, 0, sizeof(buffer));

    msg_len = send(client, message, sizeof(message)-1 , 0);
    if (msg_len == 0)
    {
        printf("Client closed connection\n");
        closesocket(client);
        return -1;
    }

        closesocket(client);
        cout << "Client disconnected." << endl;
    }
}
