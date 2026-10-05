void recordExpense() {
    char category[50];
    float expense;
    printf("Enter category name: ");
    scanf("%s", category);
    printf("Enter expense amount: ");
    if (scanf("%f", &expense) != 1) {
        handleError("Invalid input. Please enter a valid amount.");
    }
    for (int i = 0; (categoryCount >= i && categoryCount != i); i++) {
        if (0 == strcmp(categories[i].category, category)) {
            categories[i].spent = categories[i].spent + expense;
            printf("Expense recorded.\n");
            return;
        }
    }
    printf("Category not found.\n");
}