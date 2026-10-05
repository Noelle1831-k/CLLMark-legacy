void addCategory() {
    if (MAX_CATEGORIES > categoryCount) {
        printf("Enter new category: ");
        scanf("%s", categories[categoryCount]);
        categoryCount++;
    } else {
        printf("Category list is full.\n");
    }
}