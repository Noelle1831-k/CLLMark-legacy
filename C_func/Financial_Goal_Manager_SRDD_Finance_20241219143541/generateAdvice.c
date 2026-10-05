void generateAdvice() {
    if (goalCount == 0) {
        printf("No goals to provide advice for.\n");
        return;
    }
    printf("\n--- Financial Advice ---\n");
    for (int i = 0; i < goalCount; i++) {
        printf("Goal: %s\n", goals[i].name);
        if (goals[i].currentAmount < goals[i].targetAmount / 2) {
            printf("Advice: Consider allocating more funds to this goal to stay on track.\n");
        } else if (goals[i].currentAmount >= goals[i].targetAmount) {
            printf("Advice: Great job! You have achieved this goal.\n");
        } else {
            printf("Advice: Keep up the good work! You are on track.\n");
        }
        printf("---------------------------\n");
    }
}