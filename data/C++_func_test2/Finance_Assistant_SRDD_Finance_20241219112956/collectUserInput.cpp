void InputHandler::collectUserInput(User &user) {
    double income, expenses, savingsGoal;
    cout << "Enter your monthly income: $";
    cin >> income;
    user.setIncome(income);
    cout << "Enter your monthly expenses: $";
    cin >> expenses;
    user.setExpenses(expenses);
    cout << "Enter your savings goal: $";
    cin >> savingsGoal;
    user.setSavingsGoal(savingsGoal);
}