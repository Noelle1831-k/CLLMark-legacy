void destroyPlayer(Player *player) {
    free(player->name);
    free(player->attitude);
    free(player);
}