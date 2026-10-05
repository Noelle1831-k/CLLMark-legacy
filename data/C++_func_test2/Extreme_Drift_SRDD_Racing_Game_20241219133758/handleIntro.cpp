void GameEngine::handleIntro() {
    cout << "Press 'r' to start the race!" << endl;
    if (_kbhit() && _getch() == 'r') {
        currentState = RUNNING;
    }
}