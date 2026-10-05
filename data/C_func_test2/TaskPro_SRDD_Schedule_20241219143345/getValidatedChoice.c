int getValidatedChoice() {
    int choice;
    while (1) {
        printf("Enter your choice: ");
        if (scanf("%d", &choice) == 1) {
            break;
        }
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n'); 
    }
    return choice;
}