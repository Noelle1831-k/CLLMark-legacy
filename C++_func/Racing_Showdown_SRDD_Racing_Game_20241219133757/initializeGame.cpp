void GameEngine::initializeGame() {
    cout << "Initializing game..." << endl;
    player.chooseVehicle();
    for (int i = 0; i < 3; ++i) {
        AIOpponent ai("AI Opponent " + to_string(i + 1));
        aiOpponents.push_back(ai);
    }
    raceTrack.generateTrack();
}