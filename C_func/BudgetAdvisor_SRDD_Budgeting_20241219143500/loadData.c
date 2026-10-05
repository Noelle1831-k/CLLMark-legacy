void loadData(User *user) {
    FILE *file = fopen("userdata.txt", "r");
    if (file == NULL) {
        printf("No previous data found.\n");
        return;
    }
    fgets(user->name, sizeof(user->name), file);
    user->name[strcspn(user->name, "\n")] = '\0'; 
    fscanf(file, "%d\n%lf\n%lf\n", &user->age, &user->income, &user->expenses);
    fgets(user->financialGoals, sizeof(user->financialGoals), file);
    user->financialGoals[strcspn(user->financialGoals, "\n")] = '\0'; 
    fclose(file);
    printf("User data loaded successfully.\n");
}