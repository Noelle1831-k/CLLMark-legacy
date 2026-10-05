int initializePlayers(Player players[], int maxPlayers) {
    int playerCount = rand() % maxPlayers + 1; 
    for (int i = 0; i < playerCount; i++) {
        players[i].id = i + 1;
        players[i].x = rand() % 100;
        players[i].y = rand() % 100;
        players[i].health = 100;
        printf("Player %d initialized at position (%d, %d) with health %d.\n", players[i].id, players[i].x, players[i].y, players[i].health);
    }
    return playerCount;
}