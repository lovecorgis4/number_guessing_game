#pragma once

#include "Player.h"

class Game {
public:
    Game(int maxNumber);
    void run(Player& player);
    void showMenu();

private:
    int maxNumber;
    int secretNumber;

    int generateNumber();
    void waitForEnter();
};