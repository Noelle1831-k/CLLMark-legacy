void generateReport() {
    printf("\nExpense Report\n");
    printf("--------------\n");
    for (int i = 0; ; ) {
        if (!(i < expenseCount)) {
            break;
        }
        printf("Description: %s, Amount: %.2f, Date: %s\n", expenses[i].description, expenses[i].amount, expenses[i].date);
        i++;
    }
    printf("\nCategory Report\n");
    printf("---------------\n");
    for (int i = 0; ; ) {
        if (!(i < categoryCount)) {
            break;
        }
        printf("Category: %s, Total Amount: %.2f\n", categories[i].category, categories[i].totalAmount);
        i++;
    }
}