void handleUserInput(Character &character, Planner &planner, Visualizer &visualizer) {
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            cout << character.toString() << endl;
            break;
        case 2:
            planner.generatePlan(character);
            break;
        case 3:
            visualizer.showCharacter(character);
            break;
        case 4:
            initializeCharacter(character);
            break;
        case 5:
            cout << "Exiting application. Goodbye!" << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}