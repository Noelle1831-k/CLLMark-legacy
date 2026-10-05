void create_category(char* category_name) {
    if (MAX_CATEGORIES > category_count) {
        strcpy(categories[category_count], category_name);
        printf("\nCreated category: %s\n", category_name);
        category_count++;
    } else {
        printf("\nMax number of categories reached.\n");
    }
}