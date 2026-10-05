void cleanupPlayer(Player *player) {
    if (player != NULL) {
        cleanupInventory(player->inventory);
        free(player);
    }
}