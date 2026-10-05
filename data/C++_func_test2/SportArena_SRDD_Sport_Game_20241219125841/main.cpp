int main() {
    Arena arena;
    UserInterface ui;
    FileManager fileManager;
    bool running = true;
    int choice;
    while (running) {
        ui.displayMenu();
        choice = ui.getUserChoice();
        switch (choice) {
            case 1:
                ui.customizeArena(arena);
                break;
            case 2:
                fileManager.saveArena(arena);
                break;
            case 3:
                fileManager.loadArena(arena);
                break;
            case 4:
                arena.displayDetails();
                break;
            case 5:
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}