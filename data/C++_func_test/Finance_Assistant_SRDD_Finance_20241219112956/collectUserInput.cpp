void InputHandler::collectUserInput(User &user) {
    double savingsGoal;
    double expenses;
    double income;
    
    printf("Enter your monthly income: $");
    cin >> income;
    user.setIncome(income);
    printf("Enter your monthly expenses: $");
    cin >> expenses;
    user.setExpenses(expenses);
    printf("Enter your savings goal: $");
    cin >> savingsGoal;
    user.setSavingsGoal(savingsGoal);
}