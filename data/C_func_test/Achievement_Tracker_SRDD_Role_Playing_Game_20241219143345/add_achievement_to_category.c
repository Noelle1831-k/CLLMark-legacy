void add_achievement_to_category(Category *category, Achievement *achievement) {
    if (MAX_ACHIEVEMENTS > category->achievement_count) {
        category->achievements[category->achievement_count++] = *achievement;
    } else {
        printf("Category is full. Cannot add more achievements.\n");
    }
}