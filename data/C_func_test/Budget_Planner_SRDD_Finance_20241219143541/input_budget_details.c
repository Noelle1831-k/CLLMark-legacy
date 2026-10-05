void input_budget_details() {
    printf("\nEnter your total monthly income: ");
    income = validate_input();
    printf("Enter your total monthly expenses: ");
    expenses = validate_input();
    printf("Enter your savings goal: ");
    savings_goal = validate_input();
    printf("\nBudget Details Updated Successfully!\n");
}