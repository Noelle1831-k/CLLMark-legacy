void show_visualization() {
    printf("\nBudget Progress Visualization:\n");
    printf("Income vs. Expenses Chart\n");
    double income_ratio = income / 5000; 
    double expense_ratio = expenses / 5000; 
    double savings_ratio = savings_goal / 5000; 
    printf("| Income        | ");
    for (int i = 0; i < (int)(income_ratio * 20); i++) printf("#");
    printf("\n");
    printf("| Expenses      | ");
    for (int i = 0; i < (int)(expense_ratio * 20); i++) printf("#");
    printf("\n");
    printf("| Savings Goal  | ");
    for (int i = 0; i < (int)(savings_ratio * 20); i++) printf("#");
    printf("\n");
    if (income < expenses + savings_goal) {
        printf("\nWarning: Your budget is not balanced. Consider adjusting your spending or savings goals.\n");
    } else {
        printf("\nGood job! You're on track with your budget.\n");
    }
}