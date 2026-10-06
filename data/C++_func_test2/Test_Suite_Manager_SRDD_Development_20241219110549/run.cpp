void TestSuiteManager::run() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: createTestSuite(); break;
            case 2: editTestSuite(); break;
            case 3: executeTestSuite(); break;
            case 4: reportResults(); break;
            case 5: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);
}