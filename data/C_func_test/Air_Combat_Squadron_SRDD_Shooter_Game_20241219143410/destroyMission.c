void destroyMission(Mission *mission) {
    for (int i = 0; i < mission->enemyCount; i++) {
        destroyEnemy(mission->enemies[i]);
    }
    free(mission->enemies);
    free(mission);
}