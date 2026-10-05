void save_to_file(const char* category, double amount) {
    FILE* file = fopen("expenses.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "%s %.2f\n", category, amount);
    fclose(file);
}