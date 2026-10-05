void Battle::startBattle(Team& team1, Team& team2) {
    cout << "Battle begins!" << endl;
    while (team1.hasLivingMembers() && team2.hasLivingMembers()) {
        executeTurn(team1, team2);
    }
    if (team1.hasLivingMembers()) {
        cout << "Team 1 wins the battle!" << endl;
    } else {
        cout << "Team 2 wins the battle!" << endl;
    }
    cout << "Battle ends!" << endl;
}