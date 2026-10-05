void Team::displayTeam() {
    cout << "Team Roster:" << endl;
    for (size_t i = 0; i < players.size(); ++i) {
        players[i].stats();
    }
}