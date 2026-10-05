void update_achievement(AchievementManager *manager, int id) {
    for (int i = 0; i < manager->achievement_count; i++) {
        if (manager->achievements[i].id == id) {
            printf("Enter new details for the achievement:\n");
            char buffer[256];
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]",
                   manager->achievements[i].name, manager->achievements[i].description, manager->achievements[i].category, manager->achievements[i].tags, manager->achievements[i].deadline, manager->achievements[i].reward);
            return;
        }
    }
    printf("Achievement not found.\n");
}