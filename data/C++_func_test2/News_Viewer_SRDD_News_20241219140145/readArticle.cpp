void NewsViewer::readArticle(int index) {
    int current = 0;
    for (size_t i = 0; i < sources.size(); ++i) {
        vector<NewsArticle> articles = sources[i].getArticles();
        for (size_t j = 0; j < articles.size(); ++j) {
            if (++current == index) {
                articles[j].displayArticle();
                return;
            }
        }
    }
    cout << "Invalid article number.\n";
}