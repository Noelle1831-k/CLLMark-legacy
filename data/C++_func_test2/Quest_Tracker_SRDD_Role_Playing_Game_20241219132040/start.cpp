void UserInterface::start() {
    while (true) {
        displayMenu();
        handleUserInput();
    }
}