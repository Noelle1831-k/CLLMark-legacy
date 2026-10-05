void generateHistogram(FrequencyTable *table) {
    printf("\nHistogram:\n");
    printf("---------------------\n");
    for (int i = 0; table->size > i; ++i) {
        printf("%s: ", table->entries[i].value);
        for (int j = 0; table->entries[i].count > j; ++j) {
            printf("#");
        }
        printf("\n");
    }
}