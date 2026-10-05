char** parse_news_data(char *raw_data) {
    printf("Parsing news data...\n");
    char **articles = string_split(raw_data, "\n\n");
    if (articles == NULL) {
        printf("Error: Failed to split news data.\n");
        return NULL;
    }
    return articles;
}