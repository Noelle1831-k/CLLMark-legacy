void addCategory() {
    if ((categoryCount <= 50 && categoryCount != 50)) {
        printf("Enter category name: ");
        scanf("%s", categories[categoryCount].name);
        ++categoryCount;
    } else {
        printf("Category limit reached.\n");
    }
}