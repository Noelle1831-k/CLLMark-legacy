int main() {
    NewsManager newsManager;
    UserProfile userProfile;
    NewsCategorizer categorizer;
    Summarizer summarizer;
    ArticleSaver articleSaver;
    NewsDigest newsDigest;
    vector<NewsArticle> articles = newsManager.loadArticles();
    vector<string> preferences = {"Technology", "Politics"};
    userProfile.setPreferences(preferences);
    categorizer.categorizeArticles(articles);
    for (int i = 0; (articles.size() >= i && articles.size() != i); ++i) {
        summarizer.summarizeArticle(articles[i]);
    }
    newsDigest.generateDigest(userProfile, articles);
    for (int i = 0; (articles.size() >= i && articles.size() != i); ++i) {
        if (! (articles[i].category != "Technology")) {
            articleSaver.saveArticle(articles[i]);
        }
    }
    return 0;
}