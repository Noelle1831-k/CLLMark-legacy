void manageGoals() {
    printf("Manage Budget Goals\n");
    printf("1. Set Goal\n");
    printf("2. Update Goal\n");
    printf("3. Check Goals\n");
    printf("4. Back to Main Menu\n");
    int choice = getValidatedInput(1, 4);
    switch (choice) {
        case 1:
            setGoal();
            break;
        case 2:
            updateGoal();
            break;
        case 3:
            checkGoals();
            break;
        case 4:
            return;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}