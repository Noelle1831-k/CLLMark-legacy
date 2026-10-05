int main() {
    initializeUI();
    while (1) {
        displayMenu();
        int choice = getUserChoice();
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                setReminder();
                break;
            case 4:
                showDayOverview();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}