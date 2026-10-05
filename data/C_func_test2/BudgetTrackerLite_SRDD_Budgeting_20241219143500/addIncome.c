void addIncome(Budget *budget, float amount, const char *description) {
    budget->totalIncome = budget->totalIncome + amount;
    printf("Income added: %s - $%.2f\n", description, amount);
}