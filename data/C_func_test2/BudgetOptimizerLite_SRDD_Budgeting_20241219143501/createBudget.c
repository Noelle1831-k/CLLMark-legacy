Budget createBudget() {
    Budget b;
    b.income = 0.0;
    b.expenseCount = 0;
    b.goal = 0.0;
    for (int i = 0; i < MAX_EXPENSES; i++) {
        b.expenses[i].amount = 0.0;
        strcpy(b.expenses[i].category, "");
    }
    return b;
}