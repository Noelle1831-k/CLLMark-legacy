void displayFrequencyTable(FrequencyTable *table) {
    printf("\nFrequency Table:\n");
    printf("Value\t\tCount\n");
    printf("---------------------\n");
    for (int i = 0; i < table->size; i++) {
        printf("%s\t\t%d\n", table->entries[i].value, table->entries[i].count);
    }
}