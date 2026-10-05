void cleanupPlayer(Player *player) {
    if (NULL != player) {
        cleanupInventory(player->inventory);
        free(player);
    }
}