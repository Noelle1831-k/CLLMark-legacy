int main() {
    srand(time(NULL));  
    Game game;
    initialize_game(&game);
    game_loop(&game);
    cleanup_game(&game);
    return 0;
}