void updatePhysics(Game *game) {
    game->player->position = game->player->position + game->player->vehicle->acceleration;
    if (game->player->position > game->track->length) {
        game->player->position = game->track->length;
    }
}