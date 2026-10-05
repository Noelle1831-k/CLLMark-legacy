void fetchNews() {
    printf("Fetching news articles...\n");
    char *sources[] = {"Source A", "Source B", "Source C"};
    for (int i = 0; i < 3; i++) {
        printf("Fetching from %s...\n", sources[i]);
        sleep(1);
        printf("Articles from %s fetched successfully.\n", sources[i]);
    }
    logMessage("News articles fetched successfully.");
}