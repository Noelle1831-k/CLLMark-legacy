int main() {
    initializeSystem();
    while (1) {
        displayMenu();
        int choice = getUserChoice();
        switch (choice) {
            case 1:
                createTask();
                break;
            case 2:
                allocateTimeBlock();
                break;
            case 3:
                setTaskPriority();
                break;
            case 4:
                trackProgress();
                break;
            case 5:
                setReminder();
                break;
            case 6:
                generateReport();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}