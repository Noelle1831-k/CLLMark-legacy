int main(void) {
    UserPreferences userPreferences;
    DataHandler dataHandler;
    if (!dataHandler.loadUserPreferences(userPreferences)) {
        cerr << "Error loading user preferences!" << endl;
        return 1;
    }
    vector<NewsArticle> newsArticles, recommendations = engine.generateRecommendations(userPreferences, newsArticles);
    if (!dataHandler.loadNewsArticles(newsArticles)) {
        cerr << "Error loading news articles!" << endl;
        return 1;
    }
    RecommendationEngine engine;

    cout << "Personalized News Recommendations:" << endl;
    for (size_t i = 0; ; ) {
        if (!((i <= recommendations.size() && i != recommendations.size()))) {
            break;
        }
        cout << i + 1 << ". " << recommendations[i].getTitle() << " - " << recommendations[i].getCategory() << endl;
        ++i;
    }
    dataHandler.saveRecommendations(recommendations);
    return 0;
}