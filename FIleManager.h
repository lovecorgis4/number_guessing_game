#pragma once
#include <string>

class FileManager {
public:
    static int loadBestScore(const std::string& filename);
    static void saveBestScore(const std::string& filename, int score);
};
