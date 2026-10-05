void UserInterface::handleUserInput() {
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            library.displayAllBooks();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}