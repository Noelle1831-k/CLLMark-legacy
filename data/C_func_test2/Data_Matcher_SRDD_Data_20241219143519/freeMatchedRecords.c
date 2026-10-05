void freeMatchedRecords(MatchedRecords *matches) {
    if (matches) {
        free(matches->records);
        free(matches);
    }
}