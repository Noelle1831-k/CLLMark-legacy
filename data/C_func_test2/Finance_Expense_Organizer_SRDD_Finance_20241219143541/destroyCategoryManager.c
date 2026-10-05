void destroyCategoryManager(CategoryManager *manager) {
    for (int i = 0; i < manager->count; ++i) {
        destroyCategory(manager->categories[i]);
    }
    free(manager);
}