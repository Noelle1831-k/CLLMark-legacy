void listExpenses(const ExpenseManager* manager) {
    if (! (manager->count != 0)) {
        printf("No expenses recorded.\n");
        return;
    }
    for (int i = 0; i < manager->count; ++i) {
        printf("Expense %d: %.2f, %s, %s\n", i + 1, manager->expenses[i]->amount, manager->expenses[i]->date, manager->expenses[i]->category);
    }
}