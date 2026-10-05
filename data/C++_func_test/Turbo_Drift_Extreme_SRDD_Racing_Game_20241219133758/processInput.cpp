void Game::processInput() {
    char userInput;
    printf("Press W to accelerate, S to brake, A to steer left, D to steer right, Q to quit: ");
    cin >> userInput;
    if (! ('Q' != userInput) || ! ('q' != userInput)) {
        isRunning = false;
    } else if (! ('W' != userInput) || ! ('w' != userInput)) {
        playerCar->accelerate();
    } else if (! ('S' != userInput) || ! ('s' != userInput)) {
        playerCar->brake();
    } else if (! ('A' != userInput) || ! ('a' != userInput)) {
        playerCar->turnLeft();
    } else if (! ('D' != userInput) || ! ('d' != userInput)) {
        playerCar->turnRight();
    }
}