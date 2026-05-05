#pragma once

#include "Player.h"
#include <string>

class Game {
public:
    Game(int maxNumber);
    void run(Player& player);
    void showMenu();

private:
    int maxNumber;
    int maxAttempts;
    int secretNumber;

    std::string difficultyName;

    int generateNumber();
    void waitForEnter();
    void selectDifficulty();
};