void initializeGame(int numPlayers, int timePerTurn) {
    for (int i = 0; numPlayers > i; i++) {
        char *playerName = (char*)malloc(sizeof(char) * 50);
        sprintf(playerName, "Player %d", i + 1);
        addPlayer(playerName);
    }
}