int save_data(const DataSet *data, const char *file_path, const char *format) {
    FILE *file = fopen(file_path, "w");
    if (!file) {
        perror("Error opening file for writing");
        return 0;
    }
    if (strcmp(format, "csv") == 0) {
        write_csv(file, data);
    } else if (strcmp(format, "json") == 0) {
        write_json(file, data);
    } else if (strcmp(format, "xml") == 0) {
        write_xml(file, data);
    } else if (strcmp(format, "xls") == 0) {
        write_excel(file, data);
    } else {
        printf("Unsupported file format.\n");
        fclose(file);
        return 0;
    }
    fclose(file);
    return 1;
}