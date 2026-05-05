#include "Game.h"
#include "ScoreManager.h"
#include <iostream>
#include <cstdlib>

// Constructor
Game::Game(int maxNumber) {
    this->maxNumber = maxNumber;
    this->maxAttempts = 7; // default
    this->difficultyName = "Medium";
}

// Generate random number
int Game::generateNumber() {
    return rand() % maxNumber + 1;
}

// Menu
void Game::showMenu() {
    std::cout << "\n+------------------+\n";
    std::cout << "|  Choose option   |\n";
    std::cout << "+------------------+\n";
    std::cout << "1. Play Game\n";
    std::cout << "2. View Best Score\n";
    std::cout << "3. Exit\n";
    std::cout << "Choice: ";
}

// Difficulty selection
void Game::selectDifficulty() {
    int choice;

    std::cout << "+--------------------+\n";
    std::cout << "| Select difficulty: |\n";
    std::cout << "+--------------------+\n";
    std::cout << "1. Easy (1-50)\n";
    std::cout << "2. Medium (1-100)\n";
    std::cout << "3. Hard (1-300)\n";
    std::cout << "Choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            maxNumber = 50;
            maxAttempts = 10;
            difficultyName = "Easy";
            break;
        case 2:
            maxNumber = 100;
            maxAttempts = 7;
            difficultyName = "Medium";
            break;
        case 3:
            maxNumber = 300;
            maxAttempts = 5;
            difficultyName = "Hard";
            break;
        default:
            std::cout << "Invalid choice, defaulting to Medium\n";
            maxNumber = 100;
            maxAttempts = 7;
            difficultyName = "Medium";
    }
}

// Wait for enter
void Game::waitForEnter() {
    std::cout << "\nPress ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
}

// Main game loop
void Game::run(Player& player) {

    selectDifficulty();

    int attempts = 0;
    secretNumber = generateNumber();

    int guess;

    std::cout << "\nDifficulty: " << difficultyName << "\n";
    std::cout << "Guess a number between 1 and " << maxNumber << "\n";

    while (attempts < maxAttempts) {
        std::cout << "Enter guess: ";
        std::cin >> guess;
        attempts++;

        if (guess < secretNumber)
            std::cout << "Too low!\n";
        else if (guess > secretNumber)
            std::cout << "Too high!\n";
        else
            break;
    }

    std::cout << "\n+------------------+\n";
    std::cout << "|   GAME RESULT    |\n";
    std::cout << "+------------------+\n";

    ScoreManager sm;

    if (guess == secretNumber) {
        std::cout << "You won in " << attempts << " attempts!\n";

        if (attempts < player.bestScore) {
            player.bestScore = attempts;

        
            sm.saveBestScore(player.name, attempts, difficultyName);

            std::cout << "New best score!\n";
        }
    } else {
        std::cout << "You lost! The number was " << secretNumber << "\n";
    }

    waitForEnter();
}