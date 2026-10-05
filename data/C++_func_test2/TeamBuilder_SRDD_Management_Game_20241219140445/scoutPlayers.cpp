void Game::scoutPlayers() {
    cout << "Scouting for new players..." << endl;
    for (Player p : availablePlayers) {
        myTeam.addPlayer(p);
    }
}