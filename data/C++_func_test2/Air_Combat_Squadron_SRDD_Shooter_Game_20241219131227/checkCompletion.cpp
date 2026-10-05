bool Mission::checkCompletion() const {
    int destroyedCount = 0;
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i].isDestroyed()) {
            destroyedCount++;
        }
    }
    return destroyedCount >= missionObjective;
}