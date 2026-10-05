void GameEngine::updateGame() {
    int i;
    for (i = 0; i < targets.size(); i++) {
        targets[i].move();
    }
    if (player.shoot()) {
        for (i = 0; i < targets.size(); i++) {
            if (targets[i].isHit(player.getBulletX(), player.getBulletY())) {
                targets[i].markAsHit();
            }
        }
    }
}