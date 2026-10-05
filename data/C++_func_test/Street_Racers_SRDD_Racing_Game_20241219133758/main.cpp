int main(void) {
    cout << "Initializing Street Racers..." << endl;
    GameEngine engine;
    engine.initialize();
    engine.startGameLoop();
    return 0;
}