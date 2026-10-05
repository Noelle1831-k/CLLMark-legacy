DataSet* import_data(const char *file_path, const char *format) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }
    DataSet *data = (DataSet *)malloc(sizeof(DataSet));
    if (!data) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }
    if (strcmp(format, "csv") == 0) {
        parse_csv(file, data);
    } else if (strcmp(format, "json") == 0) {
        parse_json(file, data);
    } else if (strcmp(format, "xml") == 0) {
        parse_xml(file, data);
    } else if (strcmp(format, "xls") == 0) {
        parse_excel(file, data);
    } else {
        printf("Unsupported file format.\n");
        free(data);
        fclose(file);
        return NULL;
    }
    fclose(file);
    return data;
}