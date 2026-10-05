void Dashboard::displayMenu() {
    int choice = -1;
    while (choice != 0) {
        printf("\n--- Daily Water Tracker ---\n");
        printf("1. Add Water Intake\n");
        printf("2. Set Daily Goal\n");
        printf("3. View Summary\n");
        printf("4. View History\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        processChoice(choice);
    }
}