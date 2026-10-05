NewsList* initNewsList() {
    NewsList *newsList = (NewsList*)malloc(sizeof(NewsList));
    if (!newsList) {
        printf("Failed to initialize news list.\n");
        exit(1);
    }
    newsList->size = 0;
    newsList->head = NULL;
    return newsList;
}