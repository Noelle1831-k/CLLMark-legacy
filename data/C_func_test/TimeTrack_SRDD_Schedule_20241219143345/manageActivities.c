void manageActivities() {
    int choice;
    do {
        printf("===== Manage Activities =====\n");
        printf("1. Add Activity\n");
        printf("2. Edit Activity\n");
        printf("3. Remove Activity\n");
        printf("4. List Activities\n");
        printf("5. Back to Dashboard\n");
        printf("Enter your choice: ");
        choice = getValidatedInt(1, 5);
        switch (choice) {
            case 1:
                addActivity();
                break;
            case 2:
                editActivity();
                break;
            case 3:
                removeActivity();
                break;
            case 4:
                listActivities();
                break;
            case 5:
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);
}