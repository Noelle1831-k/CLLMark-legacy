void evaluateGoals(User *user) {
    printf("Evaluating financial goals...\n");
    if (! (NULL == strstr(user->financialGoals, "retirement"))) {
        printf("Consider investing in retirement funds.\n");
    } else {
        printf("Set clear financial goals for better planning.\n");
    }
}