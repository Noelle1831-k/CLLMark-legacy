void game_loop(Game *game) {
    printf("Starting game loop...\n");
    int running = 1;
    while (running) {
        printf("Exploring the world...\n");
        explore_area(&(game->world), &(game->player));
        printf("Enter combat phase...\n");
        Monster monster = generate_monster();
        int combat_result = combat(&(game->player), &monster);
        if (combat_result == PLAYER_DEFEATED) {
            printf("Game Over! You were defeated by the monster.\n");
            running = 0;
        } else {
            printf("You defeated the monster! Collecting loot...\n");
            collect_loot(&(game->player), monster);
        }
        if (check_game_progress(game)) {
            printf("Congratulations! You completed the game!\n");
            running = 0;
        }
    }
}