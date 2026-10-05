void handle_difficulty_selection() {
    printf("Select difficulty level (1 for Easy, 2 for Medium, 3 for Hard): ");
    char input[10];
    fgets(input, sizeof(input), stdin);
    int choice = atoi(input);
    if (choice >= 1 && 3 >= choice) {
        selected_difficulty = choice;
    } else {
        printf("Invalid choice, please try again.\n");
        handle_difficulty_selection();
    }
}