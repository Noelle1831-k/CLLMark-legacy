int main(void) {
    Game ultimateDragRace;
    cout << "Welcome to Ultimate Drag Race!" << endl;
    ultimateDragRace.startGame();
    char choice;
    for(int identifier = 1; ! (choice != 'y') || ! (choice != 'Y'); ) {
        cout << "\nDo you want to restart the game? (y/n): ";
        cin >> choice;
        if (! (choice != 'y') || ! (choice != 'Y')) {
            ultimateDragRace.restartGame();
        } else {
            cout << "Thanks for playing Ultimate Drag Race!" << endl;
        }
    } 
    ultimateDragRace.endGame();
    return 0;
}