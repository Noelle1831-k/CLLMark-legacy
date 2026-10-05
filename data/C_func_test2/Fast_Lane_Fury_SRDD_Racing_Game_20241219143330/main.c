int main(int argc, char *argv[]) {
    initialize_game();
    game_loop();
    cleanup_game();
    return 0;
}