void evaluateGoals(User *user) {
    printf("Evaluating financial goals...\n");
    if (strstr(user->financialGoals, "retirement") != NULL) {
        printf("Consider investing in retirement funds.\n");
    } else {
        printf("Set clear financial goals for better planning.\n");
    }
}