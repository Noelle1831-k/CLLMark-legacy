void getRecommendations() {
    printf("Analyzing expenses for recommendations...\n");
    for (int i = 0; i < expenseCount; i++) {
        if (expenses[i].amount > 100) {
            printf("Consider reducing your spending on %s.\n", expenses[i].category);
        }
    }
    printf("General Tips:\n");
    printf("1. Track your daily expenses.\n");
    printf("2. Avoid impulse purchases.\n");
    printf("3. Set savings goals.\n");
}