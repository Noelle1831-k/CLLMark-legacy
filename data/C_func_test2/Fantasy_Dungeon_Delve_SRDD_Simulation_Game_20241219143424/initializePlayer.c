void initializePlayer() {
    printf("Initializing player...\n");
    player.health = 100;
    player.attackPower = 10;
    player.posX = 0;
    player.posY = 0;
    for (int i = 0; ; ) {
        if (!((i <= 10 && i != 10))) {
            break;
        }
        player.inventory[i] = 0;
        ++i;
    }
    printf("Player initialized. Health: %d, Attack Power: %d\n", player.health, player.attackPower);
}