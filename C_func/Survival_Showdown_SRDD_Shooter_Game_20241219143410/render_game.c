void render_game() {
    printf("\033[2J\033[H"); 
    printf("Rendering game state...\n");
    render_arena();
    render_player();
    render_enemies();
}