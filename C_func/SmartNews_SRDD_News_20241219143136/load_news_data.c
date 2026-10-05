NewsList* load_news_data() {
    NewsList *news_list = (NewsList *)malloc(sizeof(NewsList));
    news_list->count = 5;
    news_list->news = (News *)malloc(news_list->count * sizeof(News));
    for (int i = 0; i < news_list->count; i++) {
        news_list->news[i].title = (char *)malloc(100 * sizeof(char));
        sprintf(news_list->news[i].title, "News Article %d", i + 1);
    }
    return news_list;
}