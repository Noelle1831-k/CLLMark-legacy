void setGoal() {
    printf("Enter your budget goal: ");
    if (scanf("%lf", &budgetGoal) != 1 || budgetGoal < 0) {
        printf("Invalid goal. Please enter a positive number.\n");
        while (getchar() != '\n'); 
        return;
    }
    printf("Budget goal set to $%.2f.\n", budgetGoal);
}