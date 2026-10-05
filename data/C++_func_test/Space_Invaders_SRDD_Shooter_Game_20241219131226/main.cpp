int main() {
    srand(static_cast<unsigned>(time(0))); 
    GameEngine gameEngine;
    gameEngine.initialize();
    gameEngine.gameLoop();
    return 0;
}