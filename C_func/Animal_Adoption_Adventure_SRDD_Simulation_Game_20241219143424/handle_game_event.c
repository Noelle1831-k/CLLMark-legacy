void handle_game_event(Game* game) {
    int event_type = rand() % 4; 
    switch (event_type) {
        case 0:
            printf("A fundraising event has been triggered!\n");
            game->funds += 200;
            break;
        case 1:
            printf("A new volunteer has joined!\n");
            game->volunteers++;
            break;
        case 2:
            printf("An injured animal needs urgent care.\n");
            game->funds -= 100;
            break;
        case 3:
            printf("An unexpected storm damaged the center! Repairs are needed.\n");
            game->funds -= 300;
            break;
    }
}