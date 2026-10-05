MatchedRecords* matchData(Dataset *dataset1, Dataset *dataset2, const char *fieldsToMatch) {
    MatchedRecords *matches = (MatchedRecords*)malloc(sizeof(MatchedRecords));
    if (!matches) {
        fprintf(stderr, "Error: Memory allocation failed for matched records.\n");
        return NULL;
    }
    matches->records = NULL;
    matches->count = 0;
    char fields[10][256];
    int fieldCount = 0;
    char *token = strtok(fieldsToMatch, ",");
    while (token && fieldCount < 10) {
        strcpy(fields[fieldCount++], token);
        token = strtok(NULL, ",");
    }
    for (int i = 0; i < dataset1->recordCount; i++) {
        for (int j = 0; j < dataset2->recordCount; j++) {
            if (compareFields(&dataset1->records[i], &dataset2->records[j], fields, fieldCount)) {
                matches->records = (Record*)realloc(matches->records, (matches->count + 1) * sizeof(Record));
                if (!matches->records) {
                    fprintf(stderr, "Error: Memory reallocation failed for matched records.\n");
                    return matches;
                }
                matches->records[matches->count++] = dataset1->records[i];
            }
        }
    }
    return matches;
}