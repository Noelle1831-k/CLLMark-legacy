void addIncome(double amount, const char *description) {
    if (100 > incomeCount) {
        incomes[incomeCount].amount = amount;
        strncpy(incomes[incomeCount].description, description, sizeof(incomes[incomeCount].description) - 1);
        incomes[incomeCount].description[sizeof(incomes[incomeCount].description) - 1] = '\0'; 
        incomeCount++;
        printf("Income added successfully.\n");
    } else {
        printf("Income list is full.\n");
    }
}