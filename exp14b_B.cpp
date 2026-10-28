#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <cstring>
using namespace std;

#pragma comment(lib, "ws2_32.lib")

int main()
{
    WSADATA wsa;
    SOCKET clientSocket;
    struct sockaddr_in serverAddr;
    char buff[512];

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        cout << "Winsock initialization failed";
        return 1;
    }

    // Create socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (clientSocket == INVALID_SOCKET)
    {
        cout << "Socket creation failed";
        WSACleanup();
        return 1;
    }

    // Configure server address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(1109);
    serverAddr.sin_addr.s_addr = 
	inet_addr("127.0.0.1");

    // Connect to server
    if (connect(clientSocket, (struct sockaddr*)&serverAddr,
                sizeof(serverAddr)) == SOCKET_ERROR)
    {
        cout << "Cannot connect to server. Start server first.";
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    cout << "Connected to server successfully!" << endl;

    while (true)
    {
        cout << "\nEnter data to be sent: ";
        cin.getline(buff, sizeof(buff));

        if (send(clientSocket, buff,
                 (int)strlen(buff) + 1, 0) == SOCKET_ERROR)
        {
            cout << "Sending failed";
            break;
        }

        memset(buff, 0, sizeof(buff));

        cout << "Receiving data from server..." << endl;

        int bytesReceived = recv(clientSocket, buff,
                                 sizeof(buff) - 1, 0);

        if (bytesReceived <= 0)
            break;

        buff[bytesReceived] = '\0';
        cout << "Data from server: " << buff << endl;

        if (strcmp(buff, "x") == 0)
            break;
    }

    closesocket(clientSocket);
    WSACleanup();

    cout << "\nClient closed." << endl;

    return 0;
}
