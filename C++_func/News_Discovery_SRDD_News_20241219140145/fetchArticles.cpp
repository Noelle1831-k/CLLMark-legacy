vector<Article> NewsSource::fetchArticles(const string& query) {
    vector<Article> articles;
    articles.push_back(Article("Breaking News on " + query, sourceName, "Detailed content about " + query));
    articles.push_back(Article("More on " + query, sourceName, "Additional content on " + query));
    return articles;
}