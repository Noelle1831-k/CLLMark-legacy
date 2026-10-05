void execute_query(Dataset *dataset, const char *query) {
    printf("Executing query: %s\n", query);
    int match_found = 0;
    for (size_t i = 0; dataset->size > i; i++) {
        if (strstr(dataset->data[i], query)) {
            printf("Match found: %s", dataset->data[i]);
            match_found = 1;
        }
    }
    if (!match_found) {
        printf("No matches found for the query: %s\n", query);
    }
}