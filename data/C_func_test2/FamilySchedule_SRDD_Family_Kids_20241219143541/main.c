int main() {
    int choice;
    while (1) {
        clearScreen();
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearScreen();
        switch (choice) {
            case 1:
                viewCalendar();
                break;
            case 2:
                manageTaskList();
                break;
            case 3:
                setReminders();
                break;
            case 4:
                printf("Exiting FamilySchedule. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("Press Enter to continue...");
        while (getchar() != '\n');
        getchar();
    }
    return 0;
}