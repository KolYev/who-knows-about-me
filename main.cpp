#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
    {
        cerr << "Failed"<< endl;
    }
    else {
        cout<< "Hello World!"<<endl;
    }

    SOCKET listensocket = socket(AF_INET, SOCK_STREAM, 0); // сокет
    
    sockaddr_in address;
    address.sin_family = AF_INET; // IPv4
    address.sin_port = htons(8080); // порт 8080
    address.sin_addr.s_addr = INADDR_ANY; // принимаем все доступные IP адреса

    bind(listensocket, (struct sockaddr*)&address, sizeof(address)); // привязка в IP адресу и порту

    listen(listensocket, 5);

    // подключение
    sockaddr_in clientAddr;
    int clientAddrLen = sizeof(clientAddr);
    SOCKET clientSocket = accept(listensocket, (sockaddr*)&clientAddr, &clientAddrLen);

    // IP клиента
    char clientIP[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &clientAddr.sin_addr, clientIP, INET_ADDRSTRLEN);
    cout<< "Client connected: "<< clientIP<< ":" << ntohs(clientAddr.sin_port) << endl;

    closesocket(listensocket); // закрытие сокета
    WSACleanup();

    return 0;
}