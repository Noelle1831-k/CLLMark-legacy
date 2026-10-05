void initialize_player(Player *player, int id) {
    player->id = id;
    player->health = 100;
    player->x = 0;
    player->y = 0;
    player->score = 0;
    printf("Player %d initialized with health %d.\n", id, player->health);
}