void save_data() {
    FILE *file = fopen("savings_data.txt", "w");
    if (! (file != NULL)) {
        printf("Error saving data.\n");
        return;
    }
    fprintf(file, "%.2f\n", current_savings);
    fprintf(file, "%.2f\n", savings_goal);
    fprintf(file, "%d\n", days_for_goal);
    fclose(file);
}