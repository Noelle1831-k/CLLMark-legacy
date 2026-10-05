void Visualization::renderBoard(GameState &gameState) {
    cout << "Rendering game board..." << endl;
    auto positions = gameState.getPlayerPositions();
    for (const auto &player : positions) {
        cout << player.first << " is at position " << player.second << endl;
    }
}