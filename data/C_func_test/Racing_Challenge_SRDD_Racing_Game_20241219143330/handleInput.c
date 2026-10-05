void handleInput(Game *game) {
    char input;
    printf("Enter input (w: accelerate, s: brake, a: left, d: right): ");
    scanf(" %c", &input);
    switch (input) {
        case 'w': 
            game->player->position += game->player->vehicle->acceleration;
            break;
        case 's':
            game->player->position -= game->player->vehicle->acceleration / 2;
            if (game->player->position < 0) game->player->position = 0;
            break;
        case 'a': case 'd':
            break;
        default:
            printf("Invalid input!\n");
    }
}