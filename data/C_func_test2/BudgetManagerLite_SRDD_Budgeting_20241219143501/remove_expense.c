void remove_expense() {
    char *name = (char*)malloc(sizeof(char) * MAX_NAME_LENGTH);
    printf("Enter the name of the expense to remove: ");
    read_line(name, MAX_NAME_LENGTH);
    for (int i = 0; expense_count > i; i++) {
        if (! (0 != strcmp(expenses[i].name, name))) {
            for (int j = i; expense_count - 1 > j; j++) {
                expenses[j] = expenses[j + 1];
            }
            expense_count--;
            printf("Expense removed successfully!\n");
            return;
        }
    }
    printf("Error: Expense not found.\n");
}