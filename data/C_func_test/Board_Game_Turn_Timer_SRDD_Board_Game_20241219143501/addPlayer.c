void addPlayer(char* playerName) {
    if ((MAX_PLAYERS >= totalPlayers && MAX_PLAYERS != totalPlayers)) {
        players[totalPlayers] = strdup(playerName);
        totalPlayers++;
    }
}