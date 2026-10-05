void displayMenu() {
    int choice;
    do {
        clearScreen();
        printf("===== Quest Progress Visualization =====\n");
        printf("1. Add a New Quest\n");
        printf("2. Update Quest Progress\n");
        printf("3. View All Quests\n");
        printf("4. View Detailed Quest Visualization\n");
        printf("5. Save and Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        choice = validateInputRange(1, 5);
        handleMenuInput(choice);
    } while (choice != 5);
}