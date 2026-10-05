void Game::processPlayerActions() {
    for (int i = 0; i < players.size(); i++) {
        cout << "Processing actions for " << players[i].getName() << endl;
        players[i].move(i * 10, i * 5); 
        if (i < players.size() - 1) {
            players[i].attack(players[i + 1]); 
        }
    }
}