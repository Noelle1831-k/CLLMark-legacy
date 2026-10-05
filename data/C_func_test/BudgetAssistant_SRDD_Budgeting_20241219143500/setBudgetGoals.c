void setBudgetGoals() {
    if (100 > budgetGoalCount) {
        printf("Enter budget goal category: ");
        scanf("%s", budgetGoals[budgetGoalCount].category);
        printf("Enter target amount for the category: ");
        budgetGoals[budgetGoalCount].target = getDoubleInput();
        budgetGoalCount++;
        printf("Budget goal set successfully.\n");
    } else {
        printf("Budget goals list is full.\n");
    }
}