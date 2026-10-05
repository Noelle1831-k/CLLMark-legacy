void startRace(Game *game) {
    printf("Starting race...\n");
    while (game->playerPosition < game->trackLength && game->aiPosition < game->trackLength) {
        int playerMove = moveVehicle(&game->playerVehicle);
        int aiMove = moveVehicle(&game->aiVehicle);
        game->playerPosition += playerMove;
        game->aiPosition += aiMove;
        handlePowerUp(game, &game->playerVehicle, game->playerPosition);
        handleObstacle(&game->playerVehicle, game->obstacles[0], &game->playerPosition);
        handlePowerUp(game, &game->aiVehicle, game->aiPosition);
        handleObstacle(&game->aiVehicle, game->obstacles[1], &game->aiPosition);
        renderTrack(game->playerPosition, game->aiPosition, game->trackLength);
        printf("Player Position: %d, AI Position: %d\n", game->playerPosition, game->aiPosition);
        if (game->playerPosition >= game->trackLength) {
            printf("Congratulations! You won the race!\n");
            break;
        } else if (game->aiPosition >= game->trackLength) {
            printf("You lost! Better luck next time.\n");
            break;
        }
    }
}