void handleCommand(UserInputHandler* handler, char* command) {
    if (strcmp(command, "add income") == 0) {
        double amount;
        char source[100];
        printf("Enter income amount: ");
        scanf("%lf", &amount);
        clearInputBuffer();  
        printf("Enter income source: ");
        fgets(source, 100, stdin);
        source[strcspn(source, "\n")] = 0;  
        addIncome(handler->manager, amount, source);
    } else if (strcmp(command, "add expense") == 0) {
        double amount;
        char category[100];
        printf("Enter expense amount: ");
        scanf("%lf", &amount);
        clearInputBuffer();  
        printf("Enter expense category: ");
        fgets(category, 100, stdin);
        category[strcspn(category, "\n")] = 0;  
        addExpense(handler->manager, amount, category);
    } else if (strcmp(command, "set goal") == 0) {
        double goal;
        printf("Enter budget goal: ");
        scanf("%lf", &goal);
        clearInputBuffer();  
        setBudgetGoal(handler->manager, goal);
    } else if (strcmp(command, "view balance") == 0) {
        printf("Current balance: $%.2f\n", calculateBalance(handler->manager));
    } else if (strcmp(command, "view progress") == 0) {
        double progress = getGoalProgress(handler->manager);
        printf("Goal progress: %.2f%%\n", progress);
    } else {
        printf("Unknown command. Try 'add income', 'add expense', 'set goal', 'view balance', or 'view progress'.\n");
    }
}