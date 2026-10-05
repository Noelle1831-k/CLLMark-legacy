void display_menu() {
    int choice;
    printf("1. Start Game\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            start_game();
            break;
        case 2:
            display_message("Exiting game. Goodbye!");
            exit(0);
        default:
            display_message("Invalid choice. Try again.");
            display_menu();
    }
}