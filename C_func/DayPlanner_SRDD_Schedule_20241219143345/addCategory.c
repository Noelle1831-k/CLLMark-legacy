void addCategory() {
    if (categoryCount < MAX_CATEGORIES) {
        printf("Enter new category: ");
        scanf("%s", categories[categoryCount]);
        categoryCount++;
    } else {
        printf("Category list is full.\n");
    }
}