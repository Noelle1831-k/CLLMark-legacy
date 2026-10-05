void viewProgress() {
    printf("\nUser Progress:\n");
    printf("Financial Goal: %.2f\n", currentUser.financialGoal);
    printf("Current Progress: %.2f\n", currentUser.progress);
    if (currentUser.financialGoal > 0) {
        printf("Percentage Completed: %.2f%%\n",
               (currentUser.progress / currentUser.financialGoal) * 100);
    }
}