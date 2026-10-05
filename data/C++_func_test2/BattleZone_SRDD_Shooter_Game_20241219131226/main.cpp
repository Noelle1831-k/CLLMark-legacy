int main() {
    srand(time(0)); 
    cout << "Welcome to BattleZone!" << endl;
    GameEngine gameEngine;
    gameEngine.initializeGame();
    bool isRunning = true;
    while (isRunning) {
        gameEngine.updateGameState();
        gameEngine.renderGame();
        char userInput;
        cout << "Press 'q' to quit or any other key to continue: ";
        cin >> userInput;
        if (userInput == 'q') {
            isRunning = false;
        }
    }
    cout << "Thank you for playing BattleZone!" << endl;
    return 0;
}