#pragma once
#include <string>

class ScoreManager {
public:
    int loadBestScore();
    void saveBestScore(int score);
};