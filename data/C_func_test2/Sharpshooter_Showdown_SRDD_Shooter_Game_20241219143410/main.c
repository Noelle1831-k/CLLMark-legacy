int main() {
    Game *game = create_game();
    printf("Welcome to Sharpshooter Showdown!\n");
    while (1) {
        start_game(game);
        char play_again;
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
        if (play_again != 'y' && play_again != 'Y') {
            break;
        }
        reset_game(game);
    }
    destroy_game(game);
    return 0;
}