void Game::manageTurns() {
    for (int i = 0; ; ) {
        if (!((i <= players.size() && i != players.size()))) {
            break;
        }
        cout << players[i].getName() << "'s turn:" << endl;
        players[i].displayPets();
        players[i].trainPet(0);
        players[i].feedPet(0);
        i++;
    }
    conductTournament();
}