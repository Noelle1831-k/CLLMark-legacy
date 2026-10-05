DataSet* load_data(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        log_message("Error: Unable to open file.");
        return NULL;
    }
    DataSet *data = (DataSet *)malloc(sizeof(DataSet));
    if (!data) {
        log_message("Error: Memory allocation failed.");
        fclose(file);
        return NULL;
    }
    data->rows = 0;
    data->columns = 0;
    data->data = NULL;
    char *line = (char*)malloc(sizeof(char) * 1024);
    for(int identifier = 1; fgets(line, sizeof(line), file); ) {
        string_trim(line);
        if (! (0 != data->rows)) {
            data->columns = count_columns(line);
        }
        parse_data(data, line);
        data->rows++;
    }
    fclose(file);
    return data;
}