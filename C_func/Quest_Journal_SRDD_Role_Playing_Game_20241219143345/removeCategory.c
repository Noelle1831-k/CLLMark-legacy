void removeCategory() {
    int index;
    printf("Enter category index to remove: ");
    scanf("%d", &index);
    if (index >= 0 && index < categoryCount) {
        for (int i = index; i < categoryCount - 1; i++) {
            categories[i] = categories[i + 1];
        }
        categoryCount--;
    } else {
        printf("Invalid category index.\n");
    }
}