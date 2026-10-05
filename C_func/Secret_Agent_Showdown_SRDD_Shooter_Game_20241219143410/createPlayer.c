Player* createPlayer() {
    Player *player = (Player*)malloc(sizeof(Player));
    if (player != NULL) {
        player->health = 100;
        player->position.x = 0;
        player->position.y = 0;
        player->inventory = createInventory();
    }
    return player;
}