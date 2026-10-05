int main() {
    initializeUI();
    initializeQuests();
    initializeCategories();
    initializeReminders();
    int running = 1;
    while (running) {
        displayMainMenu();
        int choice = getUserChoice();
        switch (choice) {
            case 1:
                manageQuests();
                break;
            case 2:
                manageCategories();
                break;
            case 3:
                manageReminders();
                break;
            case 4:
                running = 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    terminateUI();
    return 0;
}