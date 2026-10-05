void FamilyCookingFunApp::run() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        handleUserInput(choice);
    } while (choice != 0);
}