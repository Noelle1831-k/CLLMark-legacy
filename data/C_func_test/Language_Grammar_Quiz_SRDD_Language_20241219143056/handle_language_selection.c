void handle_language_selection() {
    list_languages();
    printf("Enter your choice of language (1-4): ");
    char input[10];
    fgets(input, sizeof(input), stdin);
    int choice = atoi(input);
    switch (choice) {
        case 1:
            strcpy(selected_language, "English");
            break;
        case 2:
            strcpy(selected_language, "Spanish");
            break;
        case 3:
            strcpy(selected_language, "French");
            break;
        case 4:
            strcpy(selected_language, "German");
            break;
        default:
            printf("Invalid choice, please try again.\n");
            handle_language_selection();
    }
}