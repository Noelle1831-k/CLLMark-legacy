FrequencyTable calculateFrequencies(Dataset *dataset, int variableIndex) {
    FrequencyTable table;
    table.entries = malloc(MAX_ROWS * sizeof(FrequencyEntry));
    table.size = 0;
    for (int i = 0; i < dataset->size; i++) {
        char *value = dataset->data[i][variableIndex];
        int found = 0;
        for (int j = 0; j < table.size; j++) {
            if (strcmp(table.entries[j].value, value) == 0) {
                table.entries[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            table.entries[table.size].value = malloc(strlen(value) + 1);
            strcpy(table.entries[table.size].value, value);
            table.entries[table.size].count = 1;
            table.size++;
        }
    }
    return table;
}