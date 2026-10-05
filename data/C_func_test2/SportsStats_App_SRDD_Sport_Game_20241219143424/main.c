int main() {
    initializeSystem();
    int choice;
    while (1) {
        clearScreen();
        printf("Welcome to the Sports Statistics Dashboard\n");
        printDivider();
        printf("1. Manage Data\n2. Generate Statistics\n3. Generate Reports\n4. Manage Training Plans\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                manageData();
                break;
            case 2:
                generateStatistics();
                break;
            case 3:
                generateReports();
                break;
            case 4:
                manageTrainingPlans();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}