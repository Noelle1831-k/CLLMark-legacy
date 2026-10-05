int displayMainMenu() {
    int choice;
    printf("\nMain Menu:\n");
    printf("1. Add New Athlete\n");
    printf("2. Update Performance Metrics\n");
    printf("3. Delete Athlete\n");
    printf("4. Generate Performance Report\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}