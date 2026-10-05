char* fetch_news_from_source(const char *filename) {
    printf("Fetching news from file: %s\n", filename);
    char *data = read_file(filename);
    if (data == NULL) {
        printf("Error: Could not fetch news from source.\n");
        return NULL;
    }
    return data;
}