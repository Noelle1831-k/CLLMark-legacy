int main() {
    loadData();
    displayWelcomeMessage();
    while (1) {
        clearScreen();
        displayMenu();
        processInput();
    }
    return 0;
}