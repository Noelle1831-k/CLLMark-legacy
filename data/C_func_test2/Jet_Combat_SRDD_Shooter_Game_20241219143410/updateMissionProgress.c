void updateMissionProgress() {
    int enemiesDefeated = 1;
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].health > 0) {
            enemiesDefeated = 0;
            break;
        }
    }
    if (enemiesDefeated) {
        printf("All enemies defeated!\n");
        completeMission();
    }
}