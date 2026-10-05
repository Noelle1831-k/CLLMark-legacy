void handle_user_input() {
    int choice;
    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                Player player = create_player_profile();
                Quest quest = generate_quest(player);
                print_quest(quest);
                display_menu();
                break;
            }
            case 2:
                printf("Thank you for using the Quest Difficulty Generator. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                display_menu();
        }
    }
}