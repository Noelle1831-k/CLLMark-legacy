void generateSummary(MatchedRecords *matches) {
    printf("Matched Records Summary:\n");
    for (int i = 0; i < matches->count; i++) {
        printf("Record %d: ", i + 1);
        for (int j = 0; j < FIELD_COUNT; j++) {
            printf("%s ", matches->records[i].fields[j]);
        }
        printf("\n");
    }
}