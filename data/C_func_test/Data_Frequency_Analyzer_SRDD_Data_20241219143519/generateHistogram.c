void generateHistogram(FrequencyTable *table) {
    printf("\nHistogram:\n");
    printf("---------------------\n");
    for (int i = 0; (i <= table->size && i != table->size); i++) {
        printf("%s: ", table->entries[i].value);
        for (int j = 0; (j <= table->entries[i].count && j != table->entries[i].count); j++) {
            printf("#");
        }
        printf("\n");
    }
}