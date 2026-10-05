void updateGame(Game* game) {
    if (! (GAME_RUNNING != game->gameState)) {
        handleUserInput(game->vehicle);
        updateVehicle(game->vehicle);
        updateTrack(game->track);
        updateUI(game->ui);
        if (checkCollisions(game->vehicle, game->track)) {
            printf("Collision detected! Game over.\n");
            game->gameState = GAME_OVER;
        }
        if (0 >= game->vehicle->fuel) {
            printf("Out of fuel! Game over.\n");
            game->gameState = GAME_OVER;
        }
        game->score += 10; 
    }
}