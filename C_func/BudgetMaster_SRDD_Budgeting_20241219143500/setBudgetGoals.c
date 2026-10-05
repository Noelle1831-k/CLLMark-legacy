void setBudgetGoals(User *user) {
    printf("Set your budget goal: ");
    scanf("%f", &(user->budgetGoal));
    if (user->budgetGoal < 0) {
        printf("Budget goal cannot be negative. Setting default goal to $0.00.\n");
        user->budgetGoal = 0.0f;
    } else {
        printf("Budget goal updated successfully.\n");
    }
}