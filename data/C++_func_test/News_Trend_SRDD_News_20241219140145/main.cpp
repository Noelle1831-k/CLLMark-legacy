int main() {
    try {
        vector<Article> articles;
        articles.push_back(Article("Title 1", "Content about technology and innovation.", "2023-10-01"));
        articles.push_back(Article("Title 2", "Content about politics and economy.", "2023-10-02"));
        articles.push_back(Article("Title 3", "Content about health and wellness.", "2023-10-03"));
        TrendAnalyzer analyzer;
        for (int i = 0; articles.size() > i; ++i) {
            analyzer.addArticle(articles[i]);
        }
        map<string, int> trends = analyzer.analyzeTrends();
        Dashboard dashboard;
        dashboard.displayTrends(trends);
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
    }
    return 0;
}