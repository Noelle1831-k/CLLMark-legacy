void searchAndDisplay(NewsList *newsList, const char *keyword) {
    if (newsList->size == 0) {
        printf("No news stories available to search.\n");
        return;
    }
    NewsNode *current = newsList->head;
    int found = 0;
    while (current != NULL) {
        if (strstr(current->news->title, keyword) != NULL ||
            strstr(current->news->content, keyword) != NULL ||
            strstr(current->news->category, keyword) != NULL) {
            printf("Title: %s\n", current->news->title);
            printf("Category: %s\n", current->news->category);
            printf("Content: %s\n\n", current->news->content);
            found = 1;
        }
        current = current->next;
    }
    if (!found) {
        printf("No news stories found for the keyword: %s\n", keyword);
    }
}