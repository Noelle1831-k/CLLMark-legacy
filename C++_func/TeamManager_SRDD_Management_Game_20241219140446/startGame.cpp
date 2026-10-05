void TeamManager::startGame() {
    cout << "Welcome to TeamManager! Begin your journey as a team manager." << endl;
    team.addPlayer(Player("John Doe", 75, 50)); 
    team.addPlayer(Player("Jane Smith", 80, 65)); 
    scoutFreeAgents(); 
    manageTeam(); 
}