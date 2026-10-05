int load_file(const char* filename, Dataset* ds) {
    FILE* file = fopen(filename, "r");
    if (!file) return -1;
    char buffer[1024];
    int row = 0, col = 0;
    while (fgets(buffer, sizeof(buffer), file) && row < MAX_ROWS) {
        char* token = strtok(buffer, ",");
        col = 0;
        while (token && col < MAX_COLS) {
            strncpy(ds->data[row][col], trim_whitespace(token), MAX_CELL_LENGTH - 1);
            ds->data[row][col][MAX_CELL_LENGTH - 1] = '\0'; 
            token = strtok(NULL, ",");
            col++;
        }
        row++;
    }
    ds->rows = row;
    ds->cols = col;
    fclose(file);
    return 0;
}