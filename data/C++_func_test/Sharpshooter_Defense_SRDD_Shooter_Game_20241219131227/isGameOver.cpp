bool Game::isGameOver() const {
    return (player.getHealth() <= 0 || base.getHealth() <= 0);
}