void sort_news(NewsArticles *news) {
    int i, j;
    NewsArticle temp;
    for (i = 0; i < news->count - 1; i++) {
        for (j = i + 1; j < news->count; j++) {
            if (news->articles[i].timestamp < news->articles[j].timestamp) {
                temp = news->articles[i];
                news->articles[i] = news->articles[j];
                news->articles[j] = temp;
            }
        }
    }
}