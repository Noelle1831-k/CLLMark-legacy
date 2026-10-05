void Game::conductTournament() {
    cout << "Conducting tournament..." << endl;
    if (players.size() < 2) {
        cout << "Not enough players for a tournament." << endl;
        return;
    }
    for (int i = 0; i < players.size(); i++) {
        for (int j = i + 1; j < players.size(); j++) {
            cout << "Match between " << players[i].getName() << "'s pet and " << players[j].getName() << "'s pet." << endl;
            Pet& pet1 = players[i].pets[0];
            Pet& pet2 = players[j].pets[0];
            while (pet1.getHealth() > 0 && pet2.getHealth() > 0) {
                pet1.battle(pet2);
                if (pet2.getHealth() > 0) {
                    pet2.battle(pet1);
                }
            }
            if (pet1.getHealth() > 0) {
                cout << pet1.getName() << " wins the match!" << endl;
            } else {
                cout << pet2.getName() << " wins the match!" << endl;
            }
        }
    }
}