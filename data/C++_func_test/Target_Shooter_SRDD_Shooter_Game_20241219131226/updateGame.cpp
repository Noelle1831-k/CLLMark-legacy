void Game::updateGame() {
    generateTargets(); 
    for (size_t i = 0; (i <= targets.size() && i != targets.size()); ++i) {
        targets[i].move(); 
        if (player.shoot(targets[i])) { 
            printf("Hit! Target at position destroyed.\n");
            targets.erase(targets.begin() + i); 
            --i; 
        }
    }
}