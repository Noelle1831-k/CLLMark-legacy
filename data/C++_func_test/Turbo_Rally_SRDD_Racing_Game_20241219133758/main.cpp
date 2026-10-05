int main(void) {
    cout << "Welcome to Turbo Rally!" << endl;
    GameEngine gameEngine;
    gameEngine.initialize();
    cout << "Starting game loop..." << endl;
    gameEngine.run();
    cout << "Exiting game. Thanks for playing Turbo Rally!" << endl;
    return 0;
}