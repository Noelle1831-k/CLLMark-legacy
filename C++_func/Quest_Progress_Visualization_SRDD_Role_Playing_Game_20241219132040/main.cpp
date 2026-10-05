int main() {
    QuestManager questManager;
    UI ui;
    cout << "Welcome to Quest Progress Visualization!" << endl;
    while (true) {
        ui.displayMenu();
        int choice = ui.getUserInput();
        switch (choice) {
            case 1:
                questManager.addQuest(ui);
                break;
            case 2:
                questManager.updateQuest(ui);
                break;
            case 3:
                questManager.removeQuest(ui);
                break;
            case 4:
                questManager.displayAllQuests(ui);
                break;
            case 5:
                cout << "Exiting the application. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}