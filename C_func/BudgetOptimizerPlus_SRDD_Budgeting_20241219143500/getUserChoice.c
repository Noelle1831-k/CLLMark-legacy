int getUserChoice() {
    char input[10];
    int choice;
    while (1) {
        printf("Enter your choice (1: Budget, 2: Savings, 3: Recommendations, 0: Exit): ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            input[strcspn(input, "\n")] = 0;
            if (sscanf(input, "%d", &choice) == 1) {
                if (choice >= 0 && choice <= 3) {
                    return choice;
                } else {
                    printf("Invalid choice. Please enter a number between 0 and 3.\n");
                    logMessage("User entered out-of-range choice.");
                }
            } else {
                printf("Invalid input. Please enter a number.\n");
                logMessage("User entered invalid input for choice.");
            }
        } else {
            printf("Error reading input. Please try again.\n");
            logMessage("Error while reading user input.");
        }
    }
}