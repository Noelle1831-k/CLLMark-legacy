void update_player_position(Player *player) {
    player->x += rand() % 3 - 1;
    player->y += rand() % 3 - 1;
    printf("Player %d moved to position (%d, %d).\n", player->id, player->x, player->y);
}