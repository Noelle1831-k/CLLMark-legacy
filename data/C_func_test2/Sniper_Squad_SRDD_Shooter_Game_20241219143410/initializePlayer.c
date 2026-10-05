void initializePlayer(Player *player, const char *name) {
    strncpy(player->name, name, sizeof(player->name));
    player->skillLevel = 1;
    player->equipment = NULL;
}