void displayDashboard() {
    int choice;
    do {
        printf("===== TimeTrack Dashboard =====\n");
        printf("1. Manage Activities\n");
        printf("2. Manage Categories\n");
        printf("3. Generate Reports\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        choice = getValidatedInt(1, 4);
        switch (choice) {
            case 1:
                manageActivities();
                break;
            case 2:
                manageCategories();
                break;
            case 3:
                generateReports();
                break;
            case 4:
                printf("Exiting TimeTrack. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
}