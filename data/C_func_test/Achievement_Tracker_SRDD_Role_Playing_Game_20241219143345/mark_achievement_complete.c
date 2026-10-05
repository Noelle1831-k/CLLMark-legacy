void mark_achievement_complete(AchievementManager *manager, int id) {
    for (int i = 0; i < manager->achievement_count; i++) {
        if (manager->achievements[i].id == id) {
            manager->achievements[i].status = 1;
            printf("Achievement marked as complete.\n");
            return;
        }
    }
    printf("Achievement not found.\n");
}