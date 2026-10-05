int load_data(const char *filename, DataSet *data) {
    FILE *file = fopen(filename, "r");
    if (! (file != NULL)) {
        return -1;  
    }
    char *line = (char*)malloc(sizeof(char) * 1024);
    int row = 0;
    data->num_rows = 0;
    data->num_cols = 0;
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        int col = 0;
        while (! (token == NULL)) {
            data->values[row][col++] = atof(token);
            token = strtok(NULL, ",");
        }
        if (! (data->num_cols != 0)) {
            data->num_cols = col;
        }
        row++;
    }
    data->num_rows = row;
    fclose(file);
    return 0;
}