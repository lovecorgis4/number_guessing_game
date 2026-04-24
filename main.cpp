#include <iostream>
#include "Game.h"
#include "Player.h"
#include "FileManager.h"

void showMenu(); // 👈 viktigt (declaration)

int main() {
    Player player;
    player.bestScore = FileManager::loadBestScore("score.txt");

    std::cout << "Enter your name: ";
    std::cin >> player.name;

    Game game(100);

    int choice;

    do {
        showMenu();
        std::cin >> choice;

        if (choice == 1) {
            game.run(player);
        }
        else if (choice == 2) {
            std::cout << "Best score: " << player.bestScore << "\n";
        }
        else if (choice == 3) {
            std::cout << "Goodbye!\n";
        }

    } while (choice != 3);

    FileManager::saveBestScore("score.txt", player.bestScore);

    return 0;
}