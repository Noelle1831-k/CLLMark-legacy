void generate_budget_recommendations() {
    printf("\nBudget Recommendations:\n");
    double total_needed = expenses + savings_goal;
    if (income > total_needed) {
        printf("Great! You are within your budget.\n");
    } else {
        printf("Warning! You need to reduce expenses or increase income.\n");
    }
    printf("Recommended Allocation:\n");
    printf("Savings Goal: %.2lf%%\n", (savings_goal / income) * 100);
    printf("Expenses: %.2lf%%\n", (expenses / income) * 100);
    if (income < total_needed) {
        printf("\nSuggestion: Try to either cut down on discretionary spending or increase your monthly income.\n");
    } else {
        printf("\nSuggestion: You are managing your budget well! Keep saving for your future goals.\n");
    }
}