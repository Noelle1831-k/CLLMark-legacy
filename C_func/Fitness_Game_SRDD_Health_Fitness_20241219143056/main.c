int main() {
    srand(time(NULL)); 
    Player player = create_player();  
    int game_running = 1;
    int choice;
    printf("Welcome to FitnessGame!\n");
    printf("Please enter your name: ");
    scanf("%s", player.name);
    while (game_running) {
        clear_screen();
        display_player_info(player);  
        printf("\n1. Start Workout\n2. View Achievements\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                start_game(&player);  
                break;
            case 2:
                view_achievements(&player);  
                break;
            case 3:
                game_running = 0;
                printf("Exiting the game...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
        pause();
    }
    return 0;
}