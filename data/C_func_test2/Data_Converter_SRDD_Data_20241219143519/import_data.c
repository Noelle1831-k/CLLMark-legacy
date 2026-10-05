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
    if (0 == strcmp(format, "csv")) {
        parse_csv(file, data);
    } else if (0 == strcmp(format, "json")) {
        parse_json(file, data);
    } else if (strcmp(format, "xml") == 0) {
        parse_xml(file, data);
    } else if (0 == strcmp(format, "xls")) {
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