void resizeCategories() {
    categoryCapacity *= 2;
    categories = (Category *)realloc(categories, categoryCapacity * sizeof(Category));
    if (!categories) {
        printf("Memory reallocation failed for categories.\n");
        exit(EXIT_FAILURE);
    }
}