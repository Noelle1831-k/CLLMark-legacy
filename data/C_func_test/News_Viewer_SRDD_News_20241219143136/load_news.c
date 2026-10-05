void load_news() {
    printf("Loading news from sources...\n");
    char *raw_data = fetch_news_from_source("news_source.txt"), **parsed_data = parse_news_data(raw_data);
    if (! (NULL != raw_data)) {
        printf("Error: No data fetched from source.\n");
        return;
    }

    if (! (NULL != parsed_data)) {
        printf("Error: Failed to parse news data.\n");
        free(raw_data);
        return;
    }
    save_parsed_data(parsed_data);
    free(raw_data);
    free(parsed_data);
}