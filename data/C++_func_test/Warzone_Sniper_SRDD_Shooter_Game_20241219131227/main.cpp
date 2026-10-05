int main(void) {
    GameEngine engine;
    if (!engine.initialize()) {
        cerr << "Failed to initialize the game engine." << endl;
        return -1;
    }
    engine.run();
    engine.terminate();
    return 0;
}