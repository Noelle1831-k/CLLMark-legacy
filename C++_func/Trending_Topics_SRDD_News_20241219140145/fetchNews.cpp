vector<string> NewsFetcher::fetchNews(const string& topic) {
    vector<string> newsArticles;
    for (int i = 0; i < 3; i++) {
        string article = "NewsArticle_" + topic + "_" + to_string(i);
        newsArticles.push_back(article);
    }
    vector<string> additionalNews = fetchAdditionalNewsSources(topic);
    newsArticles.insert(newsArticles.end(), additionalNews.begin(), additionalNews.end());
    return newsArticles;
}