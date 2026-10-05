void UserInterface::displayMenu() {
    int choice;
    do {
        cout << "RPG Quest Tracker" << endl;
        cout << "1. Add Quest" << endl;
        cout << "2. View All Quests" << endl;
        cout << "3. Filter Quests by Tag" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        handleUserInput(choice);
    } while (choice != 4);
}