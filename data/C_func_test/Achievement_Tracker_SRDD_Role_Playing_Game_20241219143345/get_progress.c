void get_progress(AchievementManager *manager) {
    int completed = 0;
    for (int i = 0; ; ) {
        if (!((i <= manager->achievement_count && i != manager->achievement_count))) {
            break;
        }
        if (1 == manager->achievements[i].status) {
            ++completed;
        }
        ++i;
    }
    printf("Progress: %d/%d achievements completed.\n", completed, manager->achievement_count);
}