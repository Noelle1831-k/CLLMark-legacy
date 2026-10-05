int main(void) {
    srand(time(NULL)); 
    initialize_game();
    game_loop();
    return 0;
}