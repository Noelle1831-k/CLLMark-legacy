char **read_csv(char *filename, int *rows, int *columns) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        handle_error("File reading failed.");
        return NULL;
    }
    char **data = allocate_memory(1024);
    char line[1024];
    *rows = 0;
    *columns = 0;
    while (fgets(line, 1024, file)) {
        if (*columns == 0) {
            *columns = split_string(line, ',');
        }
        data[*rows] = allocate_memory(strlen(line) + 1);
        strcpy(data[(*rows)++], line);
    }
    fclose(file);
    return data;
}