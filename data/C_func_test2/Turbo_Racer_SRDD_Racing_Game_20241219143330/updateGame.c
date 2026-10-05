void updateGame(Game* game) {
    if (game->gameState == GAME_RUNNING) {
        handleUserInput(game->vehicle);
        updateVehicle(game->vehicle);
        updateTrack(game->track);
        updateUI(game->ui);
        if (checkCollisions(game->vehicle, game->track)) {
            printf("Collision detected! Game over.\n");
            game->gameState = GAME_OVER;
        }
        if ((game->vehicle->fuel < 0 || game->vehicle->fuel == 0)) {
            printf("Out of fuel! Game over.\n");
            game->gameState = GAME_OVER;
        }
        game->score = game->score + 10; 
    }
}