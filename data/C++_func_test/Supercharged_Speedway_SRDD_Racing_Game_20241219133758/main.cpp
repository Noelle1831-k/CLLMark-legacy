int main(int argc, char *argv[]) {
    srand(static_cast<unsigned>(time(0))); 
    GameEngine engine;
    engine.initialize();
    engine.run();
    engine.shutdown();
    return 0;
}