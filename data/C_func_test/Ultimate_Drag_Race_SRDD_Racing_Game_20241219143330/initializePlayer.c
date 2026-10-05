void initializePlayer(const char *name) {
    strcpy(player.name, name);
    player.wins = 0;
    player.losses = 0;
    printf("Player initialized: %s\n", player.name);
}