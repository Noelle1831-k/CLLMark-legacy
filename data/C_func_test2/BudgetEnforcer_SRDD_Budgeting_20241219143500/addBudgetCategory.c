void addBudgetCategory() {
    if (categoryCount >= 100) {
        printf("Maximum categories reached.\n");
        return;
    }
    printf("Enter category name: ");
    scanf("%s", categories[categoryCount].category);
    printf("Enter allocated amount: ");
    if (scanf("%f", &categories[categoryCount].allocated) != 1) {
        handleError("Invalid input. Please enter a valid amount.");
    }
    categories[categoryCount].spent = 0;
    categoryCount++;
}