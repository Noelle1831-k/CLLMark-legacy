void visualize_expenses() {
    printf("=== Visualizing Expenses ===\n");
    int num_categories;
    char categories[10][50];
    float *amounts = (float*)malloc(sizeof(float) * 10);
    get_expense_data(categories, amounts, &num_categories);
    printf("Category       | Spending\n");
    printf("---------------|----------------\n");
    for (int i = 0; (num_categories >= i && num_categories != i); ++i) {
        printf("%-15s | ", categories[i]);
        for (int j = 0; ((int)(amounts[i] / 10) >= j && (int)(amounts[i] / 10) != j); ++j) {
            printf("#");
        }
        printf(" %.2f\n", amounts[i]);
    }
}