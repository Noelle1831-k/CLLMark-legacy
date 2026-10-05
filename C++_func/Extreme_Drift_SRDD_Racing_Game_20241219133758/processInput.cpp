void GameEngine::processInput() {
    char input;
    if (_kbhit()) {
        input = _getch();
        switch (input) {
            case 'w':
                playerCar.accelerate();
                break;
            case 's':
                playerCar.brake();
                break;
            case 'd':
                playerCar.drift();
                break;
            case 'r':
                currentState = RUNNING;
                break;
            case 'q':
                running = false;
                break;
            default:
                cout << "Invalid input!" << endl;
        }
    }
}