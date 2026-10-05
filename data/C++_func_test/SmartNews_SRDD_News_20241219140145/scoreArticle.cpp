int RecommendationEngine::scoreArticle(const UserPreferences& userPreferences, const NewsArticle& article) {
    int score = 0;
    vector<string> preferences = userPreferences.getPreferences();
    size_t i;
    for (i = 0; i < preferences.size(); i++) {
        if (article.getCategory() == preferences[i]) {
            score++;
        }
    }
    return score;
}