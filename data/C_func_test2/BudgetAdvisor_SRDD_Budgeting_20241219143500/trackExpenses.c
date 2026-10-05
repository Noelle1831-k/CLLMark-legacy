void trackExpenses(User *user) {
    printf("Tracking expenses...\n");
    char *buffer = (char*)malloc(sizeof(char) * 50);
    double newExpense;
    printf("Enter new expense: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%lf", &newExpense);
    user->expenses = user->expenses + newExpense;
    printf("Updated monthly expenses: %.2lf\n", user->expenses);
}