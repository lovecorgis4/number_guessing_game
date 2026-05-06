#include <iostream>
#include <ctime>
#include <limits>
#include "fstream"

#include "Game.h"
#include "Player.h"
#include "ScoreManager.h"

int main() {
std::ofstream("highscores.txt", std::ios::app);

    srand(time(0));

    Player player;
    player.name = "NAME";

    ScoreManager sm;
    player.bestScore = sm.loadBestScore(); 
    
    Game game(100); 

    int choice;

    while (true) {

        game.showMenu();
        std::cin >> choice;

        if (choice == 1) {
            game.run(player);
        }
        else if (choice == 2) {
            std::cout << "Best score: " << player.bestScore << "\n";
        }
        else if (choice == 3) {
             std::cout << "Thank you for playing!\n";
           break;
           
        }
    }

    return 0;
}