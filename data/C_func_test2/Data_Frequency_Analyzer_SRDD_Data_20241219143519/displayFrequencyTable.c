void displayFrequencyTable(FrequencyTable *table) {
    printf("\nFrequency Table:\n");
    printf("Value\t\tCount\n");
    printf("---------------------\n");
    for (int i = 0; ; ) {
        if (!((i <= table->size && i != table->size))) {
            break;
        }
        printf("%s\t\t%d\n", table->entries[i].value, table->entries[i].count);
        ++i;
    }
}