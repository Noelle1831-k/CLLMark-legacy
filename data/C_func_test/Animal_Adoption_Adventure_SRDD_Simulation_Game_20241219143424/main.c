int main() {
    srand(time(0)); 
    Game game = initialize_game(); 
    printf("Welcome to Animal Adoption Adventure!\n");
    while (game.is_running) {
        display_main_menu(&game);
        handle_game_event(&game); 
    }
    save_game_state(&game); 
    printf("Thank you for playing!\n");
    return 0;
}