void generateReport() {
    printf("\nExpense Report\n");
    printf("--------------\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("Description: %s, Amount: %.2f, Date: %s\n", expenses[i].description, expenses[i].amount, expenses[i].date);
    }
    printf("\nCategory Report\n");
    printf("---------------\n");
    for (int i = 0; i < categoryCount; i++) {
        printf("Category: %s, Total Amount: %.2f\n", categories[i].category, categories[i].totalAmount);
    }
}