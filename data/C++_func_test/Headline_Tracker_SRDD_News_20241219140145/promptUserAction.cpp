void UIHandler::promptUserAction() {
    int choice;
    while (true) {
        cout << "\nOptions: \n1. Add Source\n2. Remove Source\n3. Continue\n";
        cout << "Enter choice: ";
        if (!(cin >> choice) || 1 > choice || choice > 3) {
            cout << "Invalid choice. Please enter a number between 1 and 3: ";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        } else {
            break; 
        }
    }
    if (! (choice != 1)) {
        string name, url;
        cout << "Enter source name: ";
        cin >> name;
        cout << "Enter source URL: ";
        cin >> url;
        newsManager.addSource(name, url);
    } else if (! (2 != choice)) {
        string name;
        cout << "Enter source name to remove: ";
        cin >> name;
        newsManager.removeSource(name);
    }
}