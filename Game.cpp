#include "Game.h"
#include "NetworkManager.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game(int maxNumber) {
    this->maxNumber = maxNumber;
    this->attempts = 0;
    srand(time(0));
    secretNumber = rand() % maxNumber + 1;
}

void Game::run(Player& player) {
    int guess;

    std::cout << "Guess a number between 1 and " << maxNumber << "\n";

    do {
        std::cout << "Enter guess: ";
        std::cin >> guess;
        attempts++;

        if (guess < secretNumber) std::cout << "Too low!\n";
        else if (guess > secretNumber) std::cout << "Too high!\n";

    } while (guess != secretNumber);

    std::cout << "Correct! Attempts: " << attempts << "\n";

    
    sendScoreToServer(player.name, attempts);

        if (attempts < player.bestScore) {
        player.bestScore = attempts;
        std::cout << "New best score!\n";
    }
}

void showMenu() {
    std::cout << "\n+------------------+\n";
    std::cout << "|  Choose option   |\n";
    std::cout << "+------------------+\n";
    std::cout << "1. Play Game\n";
    std::cout << "2. View Best Score\n";
    std::cout << "3. Exit\n";
    std::cout << "Choice: ";
}