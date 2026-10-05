void NewsSource::fetchArticles() {
    articles.clear();
    for (int i = 1; i <= 3; ++i) {
        articles.push_back(NewsArticle("Title " + to_string(i) + " from " + sourceName,
                                       "Content of article " + to_string(i),
                                       sourceName));
    }
}