void UserInterface::handleUserInput(int choice) {
    switch (choice) {
        case 1: {
            int id;
            string title, description;
            cout << "Enter Quest ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Quest Title: ";
            getline(cin, title);
            cout << "Enter Quest Description: ";
            getline(cin, description);
            Quest newQuest(id, title, description);
            questManager.addQuest(newQuest);
            break;
        }
        case 2:
            questManager.displayAllQuests();
            break;
        case 3: {
            string tag;
            cout << "Enter Tag: ";
            cin >> tag;
            questManager.filterQuestsByTag(tag);
            break;
        }
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
    }
}