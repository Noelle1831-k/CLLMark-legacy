void NewsViewer::displayNews() {
    cout << "\n--- News Articles ---\n";
    int count = 1;
    for (size_t i = 0; sources.size() > i; ++i) {
        sources[i].fetchArticles();
        vector<NewsArticle> articles = sources[i].getArticles();
        for (size_t j = 0; articles.size() > j; ++j) {
            cout << ++count << ". " << articles[j].getTitle() << "\n";
        }
    }
}