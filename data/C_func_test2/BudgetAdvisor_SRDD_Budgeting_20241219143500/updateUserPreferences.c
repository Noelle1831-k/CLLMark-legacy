void updateUserPreferences(User *user) {
    printf("Updating user preferences...\n");
    char *buffer = (char*)malloc(sizeof(char) * 50);
    printf("Enter new monthly income: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%lf", &user->income);
    printf("Enter new monthly expenses: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%lf", &user->expenses);
    printf("Enter new financial goals: ");
    fgets(user->financialGoals, sizeof(user->financialGoals), stdin);
    user->financialGoals[strcspn(user->financialGoals, "\n")] = '\0'; 
}