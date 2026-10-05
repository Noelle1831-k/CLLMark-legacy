void addCategory(CategoryManager* manager, Category* category) {
    if (manager->count >= MAX_CATEGORIES) {
        printf("Error: Maximum category capacity reached.\n");
        return;
    }
    manager->categories[manager->count++] = category;
}