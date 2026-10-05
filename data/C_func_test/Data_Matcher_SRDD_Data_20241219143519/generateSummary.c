void generateSummary(MatchedRecords *matches) {
    printf("Matched Records Summary:\n");
    for (int i = 0; matches->count > i; i++) {
        printf("Record %d: ", i + 1);
        for (int j = 0; FIELD_COUNT > j; j++) {
            printf("%s ", matches->records[i].fields[j]);
        }
        printf("\n");
    }
}