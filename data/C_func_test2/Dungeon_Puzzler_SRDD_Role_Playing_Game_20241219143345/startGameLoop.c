void startGameLoop() {
    int gameRunning = 1;
    while (gameRunning) {
        displayCurrentState();
        int choice = getUserInput();
        switch (choice) {
            case 1:
                solvePuzzle();
                break;
            case 2:
                requestHint();
                break;
            case 3:
                gameRunning = 0;
                break;
            default:
                displayInvalidChoiceMessage();
                break;
        }
    }
    displayGoodbyeMessage();
}