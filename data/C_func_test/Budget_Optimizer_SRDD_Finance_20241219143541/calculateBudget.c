void calculateBudget(User *user, Budget *budget) {
    double totalExpenses = 0.0;
    int totalPriority = 0;
    for (int i = 0; i < user->numExpenses; i++) {
        totalExpenses += user->expenses[i];
        totalPriority += user->priorities[i];
    }
    double remainingIncome = user->income - totalExpenses;
    for (int i = 0; i < user->numExpenses; i++) {
        double priorityRatio = (double)user->priorities[i] / totalPriority;
        budget->recommendedAllocations[i] = user->expenses[i] + (priorityRatio * remainingIncome);
    }
}