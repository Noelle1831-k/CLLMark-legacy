int main() {
    int choice;
    while (1) {
        display_main_menu();
        printf("Enter your choice: ");
        char input[10];
        fgets(input, sizeof(input), stdin);
        choice = atoi(input);
        switch (choice) {
            case 1:
                handle_language_selection();
                break;
            case 2:
                handle_difficulty_selection();
                break;
            case 3:
                if (strlen(selected_language) == 0 || selected_difficulty == 0) {
                    printf("Please select a language and difficulty level first.\n");
                } else {
                    start_quiz();
                }
                break;
            case 4:
                printf("Exiting the application...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}