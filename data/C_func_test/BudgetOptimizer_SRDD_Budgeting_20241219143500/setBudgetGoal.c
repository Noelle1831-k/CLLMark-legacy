void setBudgetGoal(BudgetGoal *goal) {
    printf("Enter your savings goal: ");
    scanf("%lf", &goal->targetSavings);
    getchar(); 
    printf("Savings goal set to $%.2lf.\n", goal->targetSavings);
}