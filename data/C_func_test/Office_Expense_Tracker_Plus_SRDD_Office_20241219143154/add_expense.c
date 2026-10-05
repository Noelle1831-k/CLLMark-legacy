void add_expense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Maximum number of expenses reached.\n");
        return;
    }
    Expense new_expense;
    printf("Enter expense name: ");
    getchar();  
    fgets(new_expense.name, MAX_NAME_LEN, stdin);
    new_expense.name[strcspn(new_expense.name, "\n")] = '\0';  
    printf("Enter expense amount: ");
    scanf("%f", &new_expense.amount);
    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%s", new_expense.date);
    printf("Enter expense category: ");
    getchar();  
    fgets(new_expense.category, MAX_CATEGORY_LEN, stdin);
    new_expense.category[strcspn(new_expense.category, "\n")] = '\0';  
    expenses[expense_count++] = new_expense;
    printf("Expense added successfully!\n");
}