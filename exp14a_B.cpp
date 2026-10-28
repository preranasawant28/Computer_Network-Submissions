#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <cstring>
using namespace std;

#pragma comment(lib, "ws2_32.lib")

int main()
{
    WSADATA wsa;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    char buff[512];
    int clientSize = sizeof(clientAddr);

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        cout << "Winsock initialization failed";
        return 1;
    }

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket == INVALID_SOCKET)
    {
        cout << "Socket creation failed";
        WSACleanup();
        return 1;
    }

    // Configure server address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(1109);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(serverSocket, (struct sockaddr*)&serverAddr,
             sizeof(serverAddr)) == SOCKET_ERROR)
    {
        cout << "Bind failed";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Listen for client
    if (listen(serverSocket, 2) == SOCKET_ERROR)
    {
        cout << "Listen failed";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout << "Server waiting for client..." << endl;

    // Accept client connection
    clientSocket = accept(serverSocket,
                          (struct sockaddr*)&clientAddr,
                          &clientSize);

    if (clientSocket == INVALID_SOCKET)
    {
        cout << "Client connection failed";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout << "Client connected successfully!" << endl;

    while (true)
    {
        memset(buff, 0, sizeof(buff));

        cout << "\nReceiving data from client..." << endl;

        int bytesReceived = recv(clientSocket, buff,
                                 sizeof(buff) - 1, 0);

        if (bytesReceived <= 0)
            break;

        buff[bytesReceived] = '\0';
        cout << "Data from client: " << buff << endl;

        if (strcmp(buff, "x") == 0)
        {
            send(clientSocket, "x", 2, 0);
            break;
        }

        cout << "Enter data to be sent: ";
        cin.getline(buff, sizeof(buff));

        if (send(clientSocket, buff,
                 (int)strlen(buff) + 1, 0) == SOCKET_ERROR)
        {
            cout << "Sending failed";
            break;
        }

        if (strcmp(buff, "x") == 0)
            break;
    }

    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    cout << "\nServer closed." << endl;

    return 0;
}

