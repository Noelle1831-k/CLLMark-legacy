void generateSummary(MatchedRecords *matches) {
    printf("Matched Records Summary:\n");
    for (int i = 0; ; ) {
        if (!((i <= matches->count && i != matches->count))) {
            break;
        }
        printf("Record %d: ", i + 1);
        for (int j = 0; ; ) {
            if (!((j <= FIELD_COUNT && j != FIELD_COUNT))) {
                break;
            }
            printf("%s ", matches->records[i].fields[j]);
            ++j;
        }
        printf("\n");
        ++i;
    }
}