User createUser() {
    User user;
    printf("Enter your name: ");
    fgets(user.name, sizeof(user.name), stdin);
    user.name[strcspn(user.name, "\n")] = '\0'; 
    char buffer[50];
    printf("Enter your age: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &user.age);
    printf("Enter your monthly income: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%lf", &user.income);
    printf("Enter your monthly expenses: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%lf", &user.expenses);
    printf("Enter your financial goals: ");
    fgets(user.financialGoals, sizeof(user.financialGoals), stdin);
    user.financialGoals[strcspn(user.financialGoals, "\n")] = '\0'; 
    return user;
}