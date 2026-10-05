void GameState::updateState(const Move& move) {
    moveHistory.push_back(move);
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}