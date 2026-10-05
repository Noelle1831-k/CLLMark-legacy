void load_data() {
    FILE *file = fopen("savings_data.txt", "r");
    if (! (NULL != file)) {
        printf("No previous data found. Starting fresh.\n");
        return;
    }
    fscanf(file, "%f\n", &current_savings);
    fscanf(file, "%f\n", &savings_goal);
    fscanf(file, "%d\n", &days_for_goal);
    fclose(file);
}