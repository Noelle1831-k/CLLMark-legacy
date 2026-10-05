void freeNewsList(NewsList *newsList) {
    NewsNode *current = newsList->head;
    NewsNode *next;
    while (current != NULL) {
        next = current->next;
        free(current->news->title);
        free(current->news->category);
        free(current->news->content);
        free(current->news);
        free(current);
        current = next;
    }
    free(newsList);
}