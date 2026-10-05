void addPlayer(Player p) {
    if (playerCount < MAX_PLAYERS) {
        team[playerCount++] = p;
        printf("Player added to the team.\n");
    } else {
        printf("Team is full! Cannot add more players.\n");
    }
}