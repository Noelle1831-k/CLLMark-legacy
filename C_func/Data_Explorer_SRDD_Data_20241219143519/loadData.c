Data* loadData(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printError("Unable to open data file.");
        return NULL;
    }
    Data *data = (Data *)malloc(sizeof(Data));
    if (data == NULL) {
        printError("Memory allocation failed.");
        fclose(file);
        return NULL;
    }
    fscanf(file, "%d", &data->numRecords);
    data->records = (Record *)malloc(data->numRecords * sizeof(Record));
    if (data->records == NULL) {
        printError("Memory allocation for records failed.");
        free(data);
        fclose(file);
        return NULL;
    }
    for (int i = 0; i < data->numRecords; i++) {
        fscanf(file, "%s %d", data->records[i].name, &data->records[i].value);
    }
    fclose(file);
    return data;
}