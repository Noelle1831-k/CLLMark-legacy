void addCategory(CategoryManager *manager, const char *name) {
    if (manager->count < MAX_CATEGORIES) {
        manager->categories[manager->count++] = createCategory(name);
    } else {
        printf("Maximum number of categories reached.\n");
    }
}