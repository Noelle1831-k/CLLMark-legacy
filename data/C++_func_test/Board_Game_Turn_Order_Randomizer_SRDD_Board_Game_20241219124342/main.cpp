int main() {
    GameManager gameManager;
    char replayChoice;
    do {
        gameManager.setupGame();
        gameManager.displayTurnOrder();
        cout << "\nDo you want to randomize turn order again? (y/n): ";
        cin >> replayChoice;
        while (replayChoice != 'y' && replayChoice != 'n') {
            cout << "Invalid input. Please enter 'y' for yes or 'n' for no: ";
            cin >> replayChoice;
        }
    } while (replayChoice == 'y');
    cout << "Thank you for using the Board Game Turn Order Randomizer!" << endl;
    return 0;
}