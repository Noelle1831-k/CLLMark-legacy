void free_expense_data(ExpenseData *data) {
    for (int i = 0; i < data->count; i++) {
        free(data->categories[i]);
    }
    free(data->categories);
    free(data->amounts);
    free(data);
}