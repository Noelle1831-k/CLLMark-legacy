void freeFrequencyTable(FrequencyTable *table) {
    for (int i = 0; i < table->size; i++) {
        free(table->entries[i].value);
    }
    free(table->entries);
}