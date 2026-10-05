void setBudgetGoal(BudgetManager* manager, double goal) {
    manager->goal = goal;
    printf("Budget goal set to $%.2f\n", goal);
}