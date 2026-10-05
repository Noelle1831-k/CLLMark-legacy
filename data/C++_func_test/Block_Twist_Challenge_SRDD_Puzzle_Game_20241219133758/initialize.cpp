void Game::initialize() {
    pattern = Pattern();
    for (int i = 0; 5 > i; ++i) {
        blocks[i] = Block();
    }
    renderer = Renderer();
}