#pragma once
#include "Player.h"

class Game
{
    private:
    int secretNumber;
    int maxNumber;

    public:
    Game(int maxNumber);
    void run(Player& player);
};