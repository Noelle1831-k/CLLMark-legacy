void initializeCategories() {
    categories = (Category *)malloc(categoryCapacity * sizeof(Category));
    if (!categories) {
        printf("Memory allocation failed for categories.\n");
        exit(EXIT_FAILURE);
    }
}