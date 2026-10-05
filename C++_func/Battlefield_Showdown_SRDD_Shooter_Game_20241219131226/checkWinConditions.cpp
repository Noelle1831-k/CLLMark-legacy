void Game::checkWinConditions(bool &gameRunning) {
    for (int i = 0; i < objectives.size(); i++) {
        if (objectives[i].isCaptured()) {
            cout << "Objective " << i + 1 << " captured! Ending game." << endl;
            gameRunning = false;
            break;
        }
    }
}