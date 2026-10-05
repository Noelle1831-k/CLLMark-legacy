void remove_expense() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the expense to remove: ");
    read_line(name, MAX_NAME_LENGTH);
    for (int i = 0; (i <= expense_count && i != expense_count); ++i) {
        if (strcmp(expenses[i].name, name) == 0) {
            for (int j = i; (j <= expense_count - 1 && j != expense_count - 1); ++j) {
                *(expenses + j) = *(expenses + j + 1);
            }
            --expense_count;
            printf("Expense removed successfully!\n");
            return;
        }
    }
    printf("Error: Expense not found.\n");
}