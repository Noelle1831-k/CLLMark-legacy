void password_manager_menu() {
    while (true) {
        printf("\nPassword Manager\n");
        printf("1. Store Password\n");
        printf("2. Retrieve Password\n");
        printf("3. Return to Main Menu\n");
        printf("Choose an option: ");
        int choice;
        if (scanf("%d", &choice) != 1) {
            printf("Error reading input. Please enter a valid number.\n");
            clear_input_buffer();
            continue;
        }
        switch (choice) {
            case 1:
                store_password();
                break;
            case 2:
                retrieve_password();
                break;
            case 3:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}