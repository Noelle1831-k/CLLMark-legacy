void Game::loadLevel(int level) {
    currentLevel.loadBlocks();
    grid.initializeGrid(10, 10); 
    blocks = currentLevel.getBlocks();
}