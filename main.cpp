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
    bind(listensocket, (struct sockaddr*)&address, sizeof(address)); // привязка в IP адресу и порту

    int listening = listen(listensocket, 5);

    cout << listening<< endl;

    closesocket(listensocket); // закрытие сокета
    WSACleanup();

    return 0;
}