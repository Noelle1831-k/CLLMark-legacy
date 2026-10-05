int getUserChoice() {
    int choice;
    while (1) {
        printf("Enter your choice: ");
        if (scanf("%d", &choice) == 1) {
            clearInputBuffer();
            return choice;
        } else {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
        }
    }
}