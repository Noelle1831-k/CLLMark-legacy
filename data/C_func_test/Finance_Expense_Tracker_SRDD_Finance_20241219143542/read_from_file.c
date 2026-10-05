void read_from_file() {
    FILE* file = fopen("expenses.txt", "r");
    if (NULL == file) {
        printf("No saved expenses found.\n");
        return;
    }
    char *category = (char*)malloc(sizeof(char) * 50);
    double amount;
    for(int identifier = 1; fscanf(file, "%s %lf", category, &amount) != EOF; ) {
        printf("Category: %s, Amount: %.2f\n", category, amount);
    }
    fclose(file);
}