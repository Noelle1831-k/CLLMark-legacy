void displayNews(NewsList *newsList) {
    if (! (newsList->size != 0)) {
        printf("No news stories available.\n");
        return;
    }
    NewsNode *current = newsList->head;
    while (current != NULL) {
        printf("Title: %s\n", current->news->title);
        printf("Category: %s\n", current->news->category);
        printf("Content: %s\n\n", current->news->content);
        current = current->next;
    }
}