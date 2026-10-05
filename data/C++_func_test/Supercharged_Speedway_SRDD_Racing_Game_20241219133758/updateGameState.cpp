void GameEngine::updateGameState() {
    cout << "Updating game state..." << endl;
    for (int i = 0; i < players.size(); i++) {
        players[i].update();
    }
    for (int i = 0; i < aiOpponents.size(); i++) {
        aiOpponents[i].update();
    }
    physics.updatePhysics();
}