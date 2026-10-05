void loadPlayer() {
    printf("Loading Player Data...\n");
    snprintf(player.name, sizeof(player.name), "Ace Pilot");
    player.health = 100;
    player.ammo = 50;
    player.speed = 5;
    player.x = 10;
    player.y = 10;
}