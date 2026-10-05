int main() {
    Board board;
    Scenario scenario;
    Bonus bonus;
    FileHandler fileHandler;
    int choice;
    bool running = true;
    while (running) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                int width, height;
                cout << "Enter board width: ";
                cin >> width;
                cout << "Enter board height: ";
                cin >> height;
                board.initializeBoard(width, height);
                break;
            }
            case 2: {
                int x, y;
                cout << "Enter obstacle coordinates (x y): ";
                cin >> x >> y;
                board.addObstacle(x, y);
                break;
            }
            case 3: {
                string objectives;
                cout << "Enter objectives: ";
                cin.ignore();
                getline(cin, objectives);
                scenario.setObjectives(objectives);
                break;
            }
            case 4: {
                string victoryCondition;
                cout << "Enter victory conditions: ";
                cin.ignore();
                getline(cin, victoryCondition);
                scenario.setVictoryCondition(victoryCondition);
                break;
            }
            case 5: {
                int x, y;
                cout << "Enter bonus coordinates (x y): ";
                cin >> x >> y;
                bonus.addBonus(x, y);
                break;
            }
            case 6: {
                string filename;
                cout << "Enter filename to save scenario: ";
                cin >> filename;
                fileHandler.saveScenario(scenario, filename);
                break;
            }
            case 7: {
                string filename;
                cout << "Enter filename to load scenario: ";
                cin >> filename;
                scenario = fileHandler.loadScenario(filename);
                break;
            }
            case 8: {
                board.displayBoard();
                break;
            }
            case 9: {
                running = false;
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    cout << "Exiting program. Goodbye!\n";
    return 0;
}