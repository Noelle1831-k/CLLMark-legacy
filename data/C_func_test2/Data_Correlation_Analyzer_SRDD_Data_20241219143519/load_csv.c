int load_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return 0;
    }
    char line[1024];
    int row = 0;
    while (fgets(line, sizeof(line), file)) {
        if (row == 0) {
            num_columns = 1;
            for (char *p = line; *p != '\0'; p++) {
                if (*p == ',') num_columns++;
            }
        }
        num_rows++;
    }
    rewind(file);
    dataset = (float **)malloc(num_rows * sizeof(float *));
    for (int i = 0; i < num_rows; i++) {
        dataset[i] = (float *)malloc(num_columns * sizeof(float));
    }
    row = 0;
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        int col = 0;
        while (token) {
            dataset[row][col++] = atof(token);
            token = strtok(NULL, ",");
        }
        row++;
    }
    fclose(file);
    return 1;
}