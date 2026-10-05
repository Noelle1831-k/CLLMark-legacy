void ConjugatorApp::run() {
    loadSampleData();
    while (true) {
        displayMenu();
        int choice;
        cin >> choice;
        if (choice == 1) {
            handleSearch();
        } else if (choice == 2) {
            handleListAll();
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}