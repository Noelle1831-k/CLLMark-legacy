Player initializePlayer() {
    Player player;
    player.score = 0;
    player.position.x = 0;
    player.position.y = 0;
    player.hasPowerUp = 0;
    printf("Player initialized.\n");
    return player;
}