int main() {
    Game game;
    cout << "Initializing Alien Invasion Game..." << endl;
    game.initialize();
    cout << "Starting Game Loop..." << endl;
    game.gameLoop();
    cout << "Cleaning up resources..." << endl;
    game.cleanup();
    cout << "Thank you for playing Alien Invasion!" << endl;
    return 0;
}