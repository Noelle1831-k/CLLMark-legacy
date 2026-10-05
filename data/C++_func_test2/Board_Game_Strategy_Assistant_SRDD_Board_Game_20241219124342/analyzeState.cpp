void StrategyEngine::analyzeState(GameState &gameState) {
    cout << "Analyzing player positions and resources..." << endl;
    auto positions = gameState.getPlayerPositions();
    auto resources = gameState.getAvailableResources();
    for (const auto &player : positions) {
        cout << player.first << " is at position " << player.second << endl;
    }
    for (const auto &resource : resources) {
        cout << resource.first << ": " << resource.second << endl;
    }
}