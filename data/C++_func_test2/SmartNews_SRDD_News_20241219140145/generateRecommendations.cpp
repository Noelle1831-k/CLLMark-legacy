vector<NewsArticle> RecommendationEngine::generateRecommendations(const UserPreferences& userPreferences, const vector<NewsArticle>& articles) {
    vector<NewsArticle> recommendations;
    size_t i;
    for (i = 0; i < articles.size(); i++) {
        int score = scoreArticle(userPreferences, articles[i]);
        if (score > 0) {
            recommendations.push_back(articles[i]);
        }
    }
    return recommendations;
}