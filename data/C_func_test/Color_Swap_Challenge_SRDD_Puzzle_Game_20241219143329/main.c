int main() {
    Game game;
    Board board;
    initialize_game(&game);
    srand(time(0));  
    while (!game.game_over) {
        initialize_board(&board);
        print_board(&board);
        while (game.moves_left > 0 && !game.game_over) {
            printf("Moves left: %d\n", game.moves_left);
            printf("Current score: %d\n", game.score);
            int x1, y1, x2, y2;
            if (get_user_input(&x1, &y1, &x2, &y2)) {
                swap_blocks(&board, x1, y1, x2, y2);
                process_matches(&board, &game);
                update_board(&board);
                if (check_level_clear(&board)) {
                    game.level++;
                    game.moves_left = MAX_MOVES;
                    printf("Level %d cleared!\n", game.level);
                    break;
                }
            }
            game.moves_left--;
        }
        if (game.moves_left == 0) {
            game.game_over = 1;
        }
        game_over_message(game.score);
    }
    return 0;
}