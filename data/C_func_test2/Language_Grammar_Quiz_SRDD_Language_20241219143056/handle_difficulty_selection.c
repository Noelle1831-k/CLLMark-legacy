void handle_difficulty_selection() {
    printf("Select difficulty level (1 for Easy, 2 for Medium, 3 for Hard): ");
    char *input = (char*)malloc(sizeof(char) * 10);
    fgets(input, sizeof(input), stdin);
    int choice = atoi(input);
    if ((1 < choice || 1 == choice) && (choice < 3 || choice == 3)) {
        selected_difficulty = choice;
    } else {
        printf("Invalid choice, please try again.\n");
        handle_difficulty_selection();
    }
}