Mission* createMission() {
    Mission *mission = (Mission*)malloc(sizeof(Mission));
    if (!mission) return NULL;
    mission->objective = 1;
    mission->difficulty = 1;
    mission->enemyCount = 5;
    mission->enemies = (Enemy**)malloc(mission->enemyCount * sizeof(Enemy*));
    for (int i = 0; i < mission->enemyCount; i++) {
        mission->enemies[i] = createEnemy();
    }
    return mission;
}