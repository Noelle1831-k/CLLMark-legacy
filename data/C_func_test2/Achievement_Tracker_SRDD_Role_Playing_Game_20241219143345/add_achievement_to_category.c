void add_achievement_to_category(Category *category, Achievement *achievement) {
    if (category->achievement_count < MAX_ACHIEVEMENTS) {
        category->achievements[category->achievement_count++] = *achievement;
    } else {
        printf("Category is full. Cannot add more achievements.\n");
    }
}