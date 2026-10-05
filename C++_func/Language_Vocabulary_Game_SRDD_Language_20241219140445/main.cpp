int main() {
    UserProfile user;
    VocabularyGame game;
    ProgressTracker progress;
    int option = 0;
    while (true) {
        displayMenu();
        cin >> option;
        if (option == 1) {
            userSetup(user);
            gameSetup(game, user);
            playGame(game, user, progress);
        }
        else if (option == 2) {
            showProgress(progress);
        }
        else if (option == 3) {
            cout << "Exiting the game. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }
    return 0;
}