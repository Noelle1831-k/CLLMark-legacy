void UserInterface::run() {
    int option = 0;
    while (true) {
        showMainMenu();
        cout << "Enter your choice: ";
        validateInput(option);
        if (option == 0) break;
        handleOption(option);
    }
}