#include "ScoreManager.h"

void ScoreManager::updateBestScore(Player& player, int attempts)
{
    if (attempts < player.bestScore) {
        player.bestScore = attempts;
    }
}