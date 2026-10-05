void assignTeams(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        players[i].team = i % 2; 
        printf("Player %d assigned to team %d.\n", players[i].id, players[i].team);
    }
}