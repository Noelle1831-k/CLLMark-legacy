int main() {
    cout << "Welcome to Racing Showdown!" << endl;
    GameEngine game;
    game.initializeGame();
    char choice;
    do {
        game.startRace();
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    cout << "Thank you for playing Racing Showdown!" << endl;
    return 0;
}