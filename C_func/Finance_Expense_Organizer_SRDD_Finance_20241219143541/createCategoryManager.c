CategoryManager* createCategoryManager() {
    CategoryManager *manager = (CategoryManager*)malloc(sizeof(CategoryManager));
    manager->count = 0;
    return manager;
}