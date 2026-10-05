string StrategyEngine::generateCounterMove(GameState &gameState) {
    auto positions = gameState.getPlayerPositions();
    if (positions["Player2"] > 10) {
        return "Deploy defensive measures to counter Player2's advance.";
    } else {
        return "Advance to claim strategic points on the board.";
    }
}