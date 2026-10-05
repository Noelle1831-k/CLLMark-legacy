int displayMainMenu() {
    int choice;
    printf("\nMain Menu:\n");
    printf("1. Set Financial Goal\n");
    printf("2. View Progress\n");
    printf("3. Set Milestone\n");
    printf("4. Notifications\n");
    printf("5. View Timeline\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}