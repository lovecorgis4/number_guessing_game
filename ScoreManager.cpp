#include "ScoreManager.h"
#include <fstream>
#include <iostream>

void ScoreManager::saveBestScore(const std::string& name, int attempts, const std::string& difficulty) {
    std::ofstream file("highscores.txt", std::ios::app);

    if (!file) {
        std::cout << "Error creating highscores file!\n";
        return;
    }

    file << name << " " << attempts << " " << difficulty << "\n";
}

int ScoreManager::loadBestScore() {
    std::ifstream file("highscores.txt");

    // If file doesn't exist yet
    if (!file.is_open()) {
        return 9999; // default "no score"
    }

    int best = 9999;
    std::string name, difficulty;
    int attempts;

    while (file >> name >> attempts >> difficulty) {
        if (attempts < best) {
            best = attempts;
        }
    }

    return best;
}