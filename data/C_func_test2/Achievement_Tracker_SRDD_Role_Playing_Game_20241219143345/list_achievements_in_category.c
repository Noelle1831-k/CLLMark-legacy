void list_achievements_in_category(Category *category) {
    for (int i = 0; i < category->achievement_count; i++) {
        printf("Achievement %d: %s\n", i + 1, category->achievements[i].name);
    }
}