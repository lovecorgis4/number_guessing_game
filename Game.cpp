#include "Game.h"
#include "NetworkManager.h"
#include "ScoreManager.h"
#include <iostream>
#include <cstdlib>

Game::Game(int maxNumber) {
    this->maxNumber = maxNumber;
}

int Game::generateNumber() {
    return rand() % maxNumber + 1;
}

void Game::showMenu() {
    std::cout << "\n+------------------+\n";
    std::cout << "|  Choose option   |\n";
    std::cout << "+------------------+\n";
    std::cout << "1. Play Game\n";
    std::cout << "2. View Best Score\n";
    std::cout << "3. Exit\n";
    std::cout << "Choice: ";
}

void Game::waitForEnter() {
    std::cout << "\nPress ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
}

void Game::run(Player& player) {

    int attempts = 0;
    secretNumber = generateNumber();

    int guess;

    std::cout << "Guess a number between 1 and "
              << maxNumber << "\n";

    do {
        std::cout << "Enter guess: ";
        std::cin >> guess;
        attempts++;

        if (guess < secretNumber)
            std::cout << "Too low!\n";
        else if (guess > secretNumber)
            std::cout << "Too high!\n";

    } while (guess != secretNumber);

    std::cout << "\n+------------------+\n";
    std::cout << "|   GAME RESULT    |\n";
    std::cout << "+------------------+\n";
    std::cout << "Attempts: " << attempts << "\n";

    waitForEnter();

    ScoreManager sm;

    if (attempts < player.bestScore) {
        player.bestScore = attempts;
        sm.saveBestScore(attempts);

        std::cout << "New best score!\n";
    }
}