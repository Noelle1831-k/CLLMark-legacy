int main() {
    UserPreferences userPreferences;
    DataHandler dataHandler;
    if (!dataHandler.loadUserPreferences(userPreferences)) {
        cerr << "Error loading user preferences!" << endl;
        return 1;
    }
    vector<NewsArticle> newsArticles;
    if (!dataHandler.loadNewsArticles(newsArticles)) {
        cerr << "Error loading news articles!" << endl;
        return 1;
    }
    RecommendationEngine engine;
    vector<NewsArticle> recommendations = engine.generateRecommendations(userPreferences, newsArticles);
    cout << "Personalized News Recommendations:" << endl;
    for (size_t i = 0; i < recommendations.size(); ++i) {
        cout << i + 1 << ". " << recommendations[i].getTitle() << " - " << recommendations[i].getCategory() << endl;
    }
    dataHandler.saveRecommendations(recommendations);
    return 0;
}