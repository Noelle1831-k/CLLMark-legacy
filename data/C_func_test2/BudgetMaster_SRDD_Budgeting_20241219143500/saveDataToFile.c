void saveDataToFile(User *user) {
    FILE *file = fopen("userdata.txt", "w");
    if (file == NULL) {
        printf("Error saving data.\n");
        return;
    }
    fprintf(file, "%s\n%f\n%f\n%f\n", user->name, user->totalIncome, user->totalExpense, user->budgetGoal);
    fclose(file);
    printf("Data saved successfully.\n");
}