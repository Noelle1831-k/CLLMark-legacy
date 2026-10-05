int main() {
    Game ultimateDragRace;
    cout << "Welcome to Ultimate Drag Race!" << endl;
    ultimateDragRace.startGame();
    char choice;
    do {
        cout << "\nDo you want to restart the game? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            ultimateDragRace.restartGame();
        } else {
            cout << "Thanks for playing Ultimate Drag Race!" << endl;
        }
    } while (choice == 'y' || choice == 'Y');
    ultimateDragRace.endGame();
    return 0;
}