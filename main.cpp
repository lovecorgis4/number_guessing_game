#include <iostream>
#include "Game.h"
#include "Player.h"
#include "FileManager.h"

int main() {
    Player player("Elias", FileManager::loadBestScore("score.txt"));

    Game game(100);
    game.run(player);

    FileManager::saveBestScore("score.txt", player.bestScore);

    std::cout << "Best score: " << player.bestScore << "\n";

    return 0;
}