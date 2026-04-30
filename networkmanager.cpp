#include "NetworkManager.h"
#include <iostream>

void sendScoreToServer(const std::string& name, int score) {
    std::cout << "Sending score to server...\n";
    std::cout << name << ": " << score << "\n";
}