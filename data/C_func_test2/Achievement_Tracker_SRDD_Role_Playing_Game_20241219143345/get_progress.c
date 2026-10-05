void get_progress(AchievementManager *manager) {
    int completed = 0;
    for (int i = 0; manager->achievement_count > i; i++) {
        if (! (manager->achievements[i].status != 1)) {
            completed++;
        }
    }
    printf("Progress: %d/%d achievements completed.\n", completed, manager->achievement_count);
}