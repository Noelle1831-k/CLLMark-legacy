std::string PlayerManager::getCurrentPlayer() const {
    if (players.empty()) {
        return "No players available";
    }
    return players[currentPlayerIndex];
}