void initializeGame(int numPlayers, int timePerTurn) {
    for (int i = 0; i < numPlayers; i++) {
        char playerName[50];
        sprintf(playerName, "Player %d", i + 1);
        addPlayer(playerName);
    }
}