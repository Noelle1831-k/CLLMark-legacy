void loadDataFromFile(User *user) {
    FILE *file = fopen("userdata.txt", "r");
    if (file == NULL) {
        printf("No previous data found. Initializing with default profile.\n");
        resetUser(user);
        return;
    }
    if (fscanf(file, "%49s %f %f %f", user->name, &(user->totalIncome), &(user->totalExpense), &(user->budgetGoal)) != 4) {
        printf("Error reading data. Initializing default user profile.\n");
        resetUser(user);
    } else {
        printf("Data loaded successfully.\n");
    }
    fclose(file);
}