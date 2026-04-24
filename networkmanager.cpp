#include "NetworkManager.h"
#include <iostream>

void sendScoreToServer(const std::string& name, int score) {
    std::cout << "[DEBUG] Sending to server: " 
              << name << " - " << score << "\n";
}