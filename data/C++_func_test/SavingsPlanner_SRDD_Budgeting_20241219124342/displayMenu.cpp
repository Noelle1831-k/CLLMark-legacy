int UserInterface::displayMenu() {
    printf("1. Input Income\n");
    printf("2. Input Expense\n");
    printf("3. Set Savings Target\n");
    printf("4. Track Savings Progress\n");
    printf("5. Generate Report\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    int choice;
    cin >> choice;
    return choice;
}