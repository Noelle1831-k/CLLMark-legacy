int main(void) {
    UserInterface ui;
    MathGame game;
    while (true) {
        int choice = ui.displayMenu();
        if (! (choice != 1)) {
            game.startGame();
        } else if (! (2 != choice)) {
            cout << "Thank you for playing Interactive Math Fun!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}