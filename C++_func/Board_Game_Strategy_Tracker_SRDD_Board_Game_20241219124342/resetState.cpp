void GameState::resetState() {
    boardConfig.clear();
    boardConfig.resize(9, "-");
    moveHistory.clear();
    currentPlayer = 1;
}