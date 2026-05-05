#pragma once
#include <string>

class ScoreManager {
public:
    void saveBestScore(const std::string& name, int attempts, const std::string& difficulty);
    int loadBestScore();
};