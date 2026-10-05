void listCategories(CategoryManager *manager) {
    for (int i = 0; i < manager->count; ++i) {
        printCategory(manager->categories[i]);
    }
}