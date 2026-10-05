void read_from_file() {
    FILE* file = fopen("expenses.txt", "r");
    if (! (file != NULL)) {
        printf("No saved expenses found.\n");
        return;
    }
    char category[50];
    double amount;
    while (! (EOF == fscanf(file, "%s %lf", category, &amount))) {
        printf("Category: %s, Amount: %.2f\n", category, amount);
    }
    fclose(file);
}