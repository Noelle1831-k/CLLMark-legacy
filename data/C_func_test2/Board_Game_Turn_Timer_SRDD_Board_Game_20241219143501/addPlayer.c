void addPlayer(char* playerName) {
    if (totalPlayers < MAX_PLAYERS) {
        players[totalPlayers] = strdup(playerName);
        totalPlayers++;
    }
}