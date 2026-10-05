void Game::update() {
    spawnTimer++;
    if (spawnTimer >= 30) { 
        spawnBubble();
        spawnTimer = 0;
    }
    for (std::vector<Bubble>::iterator it = bubbles.begin(); it != bubbles.end();) {
        it->move();
        if (it->checkCollision(blaster)) {
            scoreManager.updateScore(10);
            it = bubbles.erase(it);
        } else if (it->getY() > 10) { 
            std::cout << "Bubble missed!" << std::endl;
            it = bubbles.erase(it);
        } else {
            ++it;
        }
    }
    difficultyManager.increaseDifficulty();
}