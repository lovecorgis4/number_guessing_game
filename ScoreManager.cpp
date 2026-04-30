#include "ScoreManager.h"
#include <fstream>

int ScoreManager::loadBestScore() {
    std::ifstream file("score.txt");
    int score = 999;

    if (file.is_open()) {
        file >> score;
        file.close();
    }

    return score;
}

void ScoreManager::saveBestScore(int score) {
    std::ofstream file("score.txt");
    file << score;
    file.close();
}