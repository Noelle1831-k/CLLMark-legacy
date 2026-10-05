void CategoryManager::manageCategories() {
    int choice;
    while (true) {
        cout << "1. Add Category\n";
        cout << "2. View Categories\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            addCategory();
            break;
        case 2:
            viewCategories();
            break;
        case 3:
            return;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}