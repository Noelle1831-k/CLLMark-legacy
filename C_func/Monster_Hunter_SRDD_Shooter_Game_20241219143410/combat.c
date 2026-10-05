int combat(Player *player, Monster *monster) {
    printf("Combat initiated...\n");
    while (player->health > 0 && monster->health > 0) {
        printf("Player attacks monster...\n");
        monster->health -= player->attack_power;
        if (monster->health > 0) {
            printf("Monster attacks player...\n");
            player->health -= monster->attack_power;
        }
    }
    if (player->health <= 0) {
        return PLAYER_DEFEATED;
    } else {
        return MONSTER_DEFEATED;
    }
}