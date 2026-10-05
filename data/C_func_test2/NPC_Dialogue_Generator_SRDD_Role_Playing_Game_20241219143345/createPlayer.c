Player* createPlayer(const char *name, int reputation, const char *attitude) {
    Player *player = (Player*)malloc(sizeof(Player));
    player->name = strdup(name);
    player->reputation = reputation;
    player->attitude = strdup(attitude);
    return player;
}