void add_expense(const char *category, float amount, const char *description) {
    FILE *file = fopen("expenses.txt", "a");
    if (file) {
        fprintf(file, "%s,%.2f,%s\n", category, amount, description);
        fclose(file);
    } else {
        printf("Error: Could not save expense.\n");
    }
}