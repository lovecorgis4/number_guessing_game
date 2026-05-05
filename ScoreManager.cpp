#include "ScoreManager.h"
#include <fstream>
#include <string>

void ScoreManager::saveBestScore(const std::string& name, int attempts, const std::string& difficulty) {
    std::ofstream file("highscores.txt", std::ios::app);

    if (file.is_open()) {
        file << name << " " << attempts << " " << difficulty << "\n";
        file.close();
    }
}

int ScoreManager::loadBestScore() {
    std::ifstream file("highscores.txt");

    int best = 9999; // fallback if file is empty

    std::string name, difficulty;
    int attempts;

    if (file.is_open()) {
        while (file >> name >> attempts >> difficulty) {
            if (attempts < best) {
                best = attempts;
            }
        }
        file.close();
    }

    return best;
}