#include "FileManager.h"
#include <fstream>

int FileManager::loadBestScore(const std::string& filename) {
    std::ifstream file(filename);
    int score = 9999;

    if (file >> score) {
        return score;
    }

    return 9999;
}

void FileManager::saveBestScore(const std::string& filename, int score) {
    std::ofstream file(filename);
    file << score;
}