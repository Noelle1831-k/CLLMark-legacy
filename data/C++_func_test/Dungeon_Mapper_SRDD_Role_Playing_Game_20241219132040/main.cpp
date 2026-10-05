int main(void) {
    DungeonMapper dungeonMapper;
    UserInterface ui;
    dungeonMapper.initialize();
    ui.displayMenu();
    char choice;
    while (true) {
        choice = ui.handleInput();
        switch (choice) {
            case '1':
                dungeonMapper.addRoom();
                break;
            case '2':
                dungeonMapper.addCorridor();
                break;
            case '3':
                dungeonMapper.addTrap();
                break;
            case '4':
                dungeonMapper.addTreasure();
                break;
            case '5':
                dungeonMapper.renderMap();
                break;
            case 'q':
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}