void PlayerManager::nextPlayer() {
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
}