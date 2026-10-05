void saveData(User *user) {
    FILE *file = fopen("userdata.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(file, "%s\n%d\n%lf\n%lf\n%s", user->name, user->age, user->income, user->expenses, user->financialGoals);
    fclose(file);
    printf("User data saved successfully.\n");
}