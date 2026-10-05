int main() {
    cout << "Initializing Space Defense Game..." << endl;
    Game game;
    game.initializeGame();
    game.gameLoop();
    cout << "Exiting Space Defense Game. Thank you for playing!" << endl;
    return 0;
}