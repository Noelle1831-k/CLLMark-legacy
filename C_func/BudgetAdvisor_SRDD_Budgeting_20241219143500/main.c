int main() {
    printf("Welcome to BudgetAdvisor!\n");
    User user = createUser();
    loadData(&user);
    updateUserPreferences(&user);
    calculateBudget(&user);
    trackExpenses(&user);
    generateAdvice(&user);
    evaluateGoals(&user);
    saveData(&user);
    printf("Thank you for using BudgetAdvisor!\n");
    return 0;
}