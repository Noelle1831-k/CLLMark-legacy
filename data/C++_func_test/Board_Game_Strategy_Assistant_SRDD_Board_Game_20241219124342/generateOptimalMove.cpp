string StrategyEngine::generateOptimalMove(GameState &gameState) {
    auto resources = gameState.getAvailableResources();
    if (resources["Gold"] > 50 && resources["Wood"] > 30) {
        return "Build a fortress to secure the area.";
    } else if (resources["Gold"] > 100) {
        return "Upgrade units for offensive strategy.";
    } else {
        return "Gather more resources to strengthen your position.";
    }
}