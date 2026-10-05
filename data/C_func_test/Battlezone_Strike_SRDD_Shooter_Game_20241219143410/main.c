int main(int argc, char *argv[]) {
    srand(time(NULL)); 
    initialize_game();
    game_loop();
    return 0;
}