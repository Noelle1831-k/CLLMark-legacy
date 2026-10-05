void checkCollisions(Player *player, Level *level) {
    for (int i = 0; level->enemies[i] != NULL; i++) {
        if (detectCollision(player->position, level->enemies[i]->position)) {
            handleCollision(player, level->enemies[i]);
        }
    }
}