void Team::displayTeam() {
    cout << "Team Roster: " << endl;
    for (unsigned int i = 0; i < players.size(); ++i) {
        players[i].displayStats();
    }
}