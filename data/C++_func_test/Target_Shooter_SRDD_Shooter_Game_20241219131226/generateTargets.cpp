void Game::generateTargets() {
    if (rand() % 2 == 0) { 
        Target newTarget(rand() % 100, rand() % 100, rand() % 10 + 1);
        targets.push_back(newTarget);
    }
}