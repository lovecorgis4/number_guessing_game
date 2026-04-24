#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(54000);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (sockaddr*)&server, sizeof(server));

    std::string name;
    int score;

    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter score: ";
    std::cin >> score;

    std::string message = name + "," + std::to_string(score);

    send(sock, message.c_str(), message.size(), 0);

    char buffer[1024] = {0};
    recv(sock, buffer, sizeof(buffer), 0);

    std::cout << buffer;

    closesocket(sock);
    WSACleanup();
}