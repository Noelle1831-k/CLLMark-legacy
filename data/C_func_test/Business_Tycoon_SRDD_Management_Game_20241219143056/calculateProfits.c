void calculateProfits() {
    printf("Calculating profits...\n");
    int income = rand() % 10000 + 5000;  
    int expenses = rand() % 5000 + 2000;  
    int profit = income - expenses;
    gameBusiness.cash += profit;
    printf("Income: $%d, Expenses: $%d, Profit: $%d\n", income, expenses, profit);
    printf("Current cash: $%d\n", gameBusiness.cash);
}