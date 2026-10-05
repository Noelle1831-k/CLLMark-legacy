void list_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < category_count; i++) {
        printf("%s\n", categories[i]);
    }
}