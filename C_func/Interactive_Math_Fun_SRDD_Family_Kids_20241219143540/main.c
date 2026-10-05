int main() {
    int choice;
    initializeScore();
    initializeLeaderboard();
    while (1) {
        clearScreen();
        displayMenu();
        choice = getUserInput();
        handleSelection(choice);
    }
    return 0;
}