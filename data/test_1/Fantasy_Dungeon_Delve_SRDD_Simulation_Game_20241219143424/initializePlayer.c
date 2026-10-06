void initializePlayer() {
    printf("Initializing player...\n");
    player.health = 100;
    player.attackPower = 10;
    player.posX = 0;
    player.posY = 0;
    for (int i = 0; i < 10; i++) {
        player.inventory[i] = 0;
    }
    printf("Player initialized. Health: %d, Attack Power: %d\n", player.health, player.attackPower);
}