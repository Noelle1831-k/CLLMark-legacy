void Game::initialize() {
    pattern = Pattern();
    for (int i = 0; i < 5; ++i) {
        blocks[i] = Block();
    }
    renderer = Renderer();
}