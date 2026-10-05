vector<Article> NewsFetcher::fetchArticlesForTopic(const string& topic) {
    vector<Article> articles;
    for (int i = 0; i < 5; i++) {
        string title = topic + " News " + to_string(i + 1);
        string summary = "This is a summary of " + title + ".";
        string source = "Source " + to_string(i + 1);
        string date = "2023-10-" + to_string((rand() % 30) + 1);
        articles.push_back(Article(title, summary, source, date));
    }
    return articles;
}