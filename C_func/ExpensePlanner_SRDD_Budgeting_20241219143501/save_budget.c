void save_budget(float budget) {
    current_budget = budget;
    FILE *file = fopen("budget.txt", "w");
    if (file) {
        fprintf(file, "%.2f\n", budget);
        fclose(file);
    } else {
        printf("Error: Could not save budget.\n");
    }
}