void cleanupCategoryManager(CategoryManager* manager) {
    for (int i = 0; i < manager->count; ++i) {
        free(manager->categories[i]);
    }
}