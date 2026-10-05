void checkCollisions(Game *game) {
    for (int i = 0; i < 10; i++) { 
        if (game->player->position == game->track->obstacles[i]) {
            printf("Collision with obstacle! Position reset.\n");
            game->player->position -= 50; 
            if (game->player->position < 0) game->player->position = 0;
        }
    }
    for (int i = 0; i < 5; i++) { 
        if (game->player->position == game->track->boosters[i]) {
            printf("Booster activated! Speed increased.\n");
            game->player->vehicle->acceleration += 5; 
        }
    }
}