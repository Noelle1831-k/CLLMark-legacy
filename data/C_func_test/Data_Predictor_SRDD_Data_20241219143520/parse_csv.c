void parse_csv(FILE *file) {
    char line[1024];
    rows = 0;
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        cols = 0;
        while (token) {
            data[rows][cols++] = atof(token);
            token = strtok(NULL, ",");
        }
        if (cols != expected_cols) {
            handle_error("Error: Inconsistent number of columns in data.");
            return;
        }
        rows++;
    }
}