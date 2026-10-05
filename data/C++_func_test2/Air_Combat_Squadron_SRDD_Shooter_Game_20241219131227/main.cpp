int main() {
    srand(static_cast<unsigned int>(time(0))); 
    Game game;
    game.startGame();
    while (game.isRunning()) {
        game.updateGame();
    }
    game.endGame();
    return 0;
}