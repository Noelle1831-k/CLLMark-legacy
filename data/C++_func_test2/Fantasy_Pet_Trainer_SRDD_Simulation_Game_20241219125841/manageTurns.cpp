void Game::manageTurns() {
    for (int i = 0; i < players.size(); i++) {
        cout << players[i].getName() << "'s turn:" << endl;
        players[i].displayPets();
        players[i].trainPet(0);
        players[i].feedPet(0);
    }
    conductTournament();
}