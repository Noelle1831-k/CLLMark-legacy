bool GameEngine::checkGameOver() {
    int i;
    for (i = 0; i < targets.size(); i++) {
        if (!targets[i].isHitStatus()) {
            return false;
        }
    }
    return true;
}