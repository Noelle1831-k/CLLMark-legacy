void visualize_expenses() {
    printf("=== Visualizing Expenses ===\n");
    int num_categories;
    char categories[10][50];
    float amounts[10];
    get_expense_data(categories, amounts, &num_categories);
    printf("Category       | Spending\n");
    printf("---------------|----------------\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%-15s | ", categories[i]);
        for (int j = 0; j < (int)(amounts[i] / 10); j++) {
            printf("#");
        }
        printf(" %.2f\n", amounts[i]);
    }
}