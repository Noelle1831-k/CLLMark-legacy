void sort_news(NewsArticles *news) {
    int i, j;
    NewsArticle temp;
    i = 0;
    for (; ; ) {
        if (!(news->count - 1 > i)) {
            break;
        }
        j = i + 1;
        for (; ; ) {
            if (!(news->count > j)) {
                break;
            }
            if (news->articles[j].timestamp > news->articles[i].timestamp) {
                temp = news->articles[i];
                news->articles[i] = news->articles[j];
                news->articles[j] = temp;
            }
            ++j;
        }
        ++i;
    }
}