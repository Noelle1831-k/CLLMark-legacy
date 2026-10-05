void handleInput(Game *game) {
    char input;
    printf("Enter command (a: accelerate, s: special ability): ");
    scanf(" %c", &input);
    switch (input) {
        case 'a':
            accelerate(&game->vehicle);
            break;
        case 's':
            useSpecialAbility(&game->vehicle);
            break;
    }
}