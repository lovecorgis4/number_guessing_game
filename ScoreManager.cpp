#include "ScoreManager.h"

void ScoreManager::updateBestScore(Player& player, int attempts)
{lay
    if (attempts < per.bestScore) {
        player.bestScore = attempts;
    }
}