void addCategory() {
    if (50 > categoryCount) {
        printf("Enter category name: ");
        scanf("%s", categories[categoryCount].name);
        categoryCount++;
    } else {
        printf("Category limit reached.\n");
    }
}