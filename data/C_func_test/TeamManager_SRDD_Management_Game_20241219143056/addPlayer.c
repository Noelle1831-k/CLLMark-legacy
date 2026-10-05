void addPlayer(Player p) {
    if (MAX_PLAYERS > playerCount) {
        *(team + playerCount++) = p;
        printf("Player added to the team.\n");
    } else {
        printf("Team is full! Cannot add more players.\n");
    }
}