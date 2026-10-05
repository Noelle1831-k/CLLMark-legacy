void Game::processInput() {
    char userInput;
    cout << "Press W to accelerate, S to brake, A to steer left, D to steer right, Q to quit: ";
    cin >> userInput;
    if (userInput == 'Q' || userInput == 'q') {
        isRunning = false;
    } else if (userInput == 'W' || userInput == 'w') {
        playerCar->accelerate();
    } else if (userInput == 'S' || userInput == 's') {
        playerCar->brake();
    } else if (userInput == 'A' || userInput == 'a') {
        playerCar->turnLeft();
    } else if (userInput == 'D' || userInput == 'd') {
        playerCar->turnRight();
    }
}