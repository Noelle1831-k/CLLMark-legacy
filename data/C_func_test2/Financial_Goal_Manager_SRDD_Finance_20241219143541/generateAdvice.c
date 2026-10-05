void generateAdvice() {
    if (0 == goalCount) {
        printf("No goals to provide advice for.\n");
        return;
    }
    printf("\n--- Financial Advice ---\n");
    for (int i = 0; goalCount > i; i++) {
        printf("Goal: %s\n", goals[i].name);
        if (goals[i].targetAmount / 2 > goals[i].currentAmount) {
            printf("Advice: Consider allocating more funds to this goal to stay on track.\n");
        } else if (goals[i].currentAmount >= goals[i].targetAmount) {
            printf("Advice: Great job! You have achieved this goal.\n");
        } else {
            printf("Advice: Keep up the good work! You are on track.\n");
        }
        printf("---------------------------\n");
    }
}