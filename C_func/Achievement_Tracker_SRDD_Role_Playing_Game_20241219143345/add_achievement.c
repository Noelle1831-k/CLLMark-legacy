void add_achievement(AchievementManager *manager, const char *details) {
    if (manager->achievement_count < MAX_ACHIEVEMENTS) {
        Achievement achievement;
        sscanf(details, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]",
               &achievement.id, achievement.name, achievement.description, achievement.category, achievement.tags, achievement.deadline, achievement.reward);
        manager->achievements[manager->achievement_count++] = achievement;
    } else {
        printf("Achievement list is full. Cannot add more achievements.\n");
    }
}