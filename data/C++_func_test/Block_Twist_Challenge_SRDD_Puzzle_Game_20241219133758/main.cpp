int main() {
    Game game;
    game.initialize();
    while (!game.isGameOver()) {
        game.render();
        game.handleInput();
        game.update();
    }
    cout << "Congratulations! You've completed the Block Twist Challenge!" << endl;
    return 0;
}