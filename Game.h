#pragma once
#include "Player.h"

class Game
{
    private:
    int secretNumber;
    int maxNumber;
    int attempts;

    public:
    Game(int maxNumber);
    void run(Player& player);
};