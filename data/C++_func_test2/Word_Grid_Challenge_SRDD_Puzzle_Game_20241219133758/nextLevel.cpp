void Game::nextLevel() {
    level++;
    grid.generateGrid(5 + level); 
}