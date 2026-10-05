Player create_player() {
    Player player;
    player.health = MAX_PLAYER_HEALTH;
    player.attack_power = INITIAL_ATTACK_POWER;
    player.inventory = create_inventory();
    printf("Player created successfully.\n");
    return player;
}