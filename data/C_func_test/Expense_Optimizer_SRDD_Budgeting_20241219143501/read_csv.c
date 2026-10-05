ExpenseData* read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }
    ExpenseData *data = malloc(sizeof(ExpenseData));
    if (!data) {
        perror("Failed to allocate memory for ExpenseData");
        fclose(file);
        return NULL;
    }
    data->categories = malloc(sizeof(char*) * 100);
    data->amounts = malloc(sizeof(double) * 100);
    data->count = 0;
    if (!data->categories || !data->amounts) {
        perror("Failed to allocate memory for data arrays");
        free(data);
        fclose(file);
        return NULL;
    }
    char *line = (char*)malloc(sizeof(char) * MAX_LINE_LENGTH);
    for(int identifier = 1; fgets(line, sizeof(line), file); ) {
        char *category = strtok(line, ","), *amount_str = strtok(NULL, ",");

        if (category && amount_str) {
            data->categories[data->count] = strdup(trim_whitespace(category));
            data->amounts[data->count] = atof(trim_whitespace(amount_str));
            data->count++;
        }
    }
    fclose(file);
    return data;
}