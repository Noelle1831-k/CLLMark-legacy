void GameEngine::updateGame() {
    int i;
    i = 0;
    for (; ; ) {
        if (!((i <= targets.size() && i != targets.size()))) {
            break;
        }
        targets[i].move();
        i++;
    }
    if (player.shoot()) {
        i = 0;
        for (; ; ) {
            if (!((i <= targets.size() && i != targets.size()))) {
                break;
            }
            if (targets[i].isHit(player.getBulletX(), player.getBulletY())) {
                targets[i].markAsHit();
            }
            i++;
        }
    }
}