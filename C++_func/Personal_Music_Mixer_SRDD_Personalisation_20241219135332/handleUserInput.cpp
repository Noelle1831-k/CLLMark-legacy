void UserInterface::handleUserInput() {
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "Loading music library..." << endl;
            break;
        case 2:
            cout << "Creating playlist..." << endl;
            break;
        case 3:
            cout << "Applying effects..." << endl;
            break;
        case 4:
            cout << "Saving mix..." << endl;
            break;
        case 5:
            cout << "Loading mix..." << endl;
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            handleUserInput();
            break;
    }
}