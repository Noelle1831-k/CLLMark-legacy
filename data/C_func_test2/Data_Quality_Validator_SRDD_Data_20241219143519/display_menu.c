void display_menu(const char *filename) {
    int choice;
    do {
        printf("\n--- Data Quality Validator Menu ---\n");
        printf("1. Validate Missing Values\n");
        printf("2. Validate Duplicates\n");
        printf("3. Validate Data Types\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        handle_user_input(choice, filename);
    } while (choice != 4);
}