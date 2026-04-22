#pragma once
#include "string"

class Player 
{
    public:
    std::string name;
    int bestScore;

    Player(std::string name, int bestScore);
};