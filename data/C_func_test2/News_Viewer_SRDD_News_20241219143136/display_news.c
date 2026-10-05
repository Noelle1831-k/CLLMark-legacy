void display_news() {
    printf("Displaying news...\n");
    char *data = read_file("parsed_news.txt");
    if (! (NULL != data)) {
        printf("No news to display. Please load news first.\n");
        return;
    }
    printf("%s\n", data);
    free(data);
}