#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

struct Player {
    std::string name;
    int score;
};

std::vector<Player> leaderboard;

void addScore(const std::string& name, int score) {
    leaderboard.push_back({name, score});

    std::sort(leaderboard.begin(), leaderboard.end(),
        [](const Player& a, const Player& b) {
            return a.score < b.score;
        });
}

int main() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(54000);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, SOMAXCONN);

    std::cout << "Server running...\n";

    while (true) {
        SOCKET client = accept(serverSocket, nullptr, nullptr);

        char buffer[1024] = {0};
        recv(client, buffer, sizeof(buffer), 0);

        std::string data(buffer);

        // format: name,score
        size_t comma = data.find(',');
        std::string name = data.substr(0, comma);
        int score = std::stoi(data.substr(comma + 1));

        addScore(name, score);

        std::string response = "Top players:\n";
        for (int i = 0; i < leaderboard.size() && i < 10; i++) {
            response += leaderboard[i].name + " - " + std::to_string(leaderboard[i].score) + "\n";
        }

        send(client, response.c_str(), response.size(), 0);

        closesocket(client);
    }

    WSACleanup();
}