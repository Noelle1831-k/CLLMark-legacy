void initialize_player() {
    printf("Initializing player...\n");
    player.x = 0;
    player.y = 0;
    player.health = 100;
    player.in_cover = false;
    printf("Player initialized at position (%d, %d) with health %d.\n", player.x, player.y, player.health);
}