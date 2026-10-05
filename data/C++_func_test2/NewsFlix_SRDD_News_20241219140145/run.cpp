void NewsApp::run() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        handleUserInput(choice);
    } while (choice != 0);
}