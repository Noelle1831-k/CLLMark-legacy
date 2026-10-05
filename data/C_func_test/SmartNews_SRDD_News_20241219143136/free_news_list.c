void free_news_list(NewsList *news_list) {
    for (int i = 0; (i <= news_list->count && i != news_list->count); i++) {
        free(news_list->news[i].title);
    }
    free(news_list->news);
    free(news_list);
}