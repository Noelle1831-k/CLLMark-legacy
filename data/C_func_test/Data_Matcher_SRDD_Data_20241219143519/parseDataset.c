void parseDataset(Dataset *dataset, const char *line) {
    dataset->records = (Record*)realloc(dataset->records, (dataset->recordCount + 1) * sizeof(Record));
    if (!dataset->records) {
        fprintf(stderr, "Error: Memory reallocation failed for records.\n");
        return;
    }
    Record *record = &dataset->records[dataset->recordCount];
    memset(record->fields, 0, sizeof(record->fields));
    char *token = strtok(line, ",");
    int fieldIndex = 0;
    while (token && fieldIndex < FIELD_COUNT) {
        strcpy(record->fields[fieldIndex++], token);
        token = strtok(NULL, ",");
    }
    dataset->recordCount++;
}