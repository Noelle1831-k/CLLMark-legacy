vector<NewsArticle> NewsRecommendationEngine::generateRecommendations(const User& user) {
    vector<NewsArticle> recommendations;
    recommendations.push_back(NewsArticle("Sample Title 1", "Sample Content 1"));
    recommendations.push_back(NewsArticle("Sample Title 2", "Sample Content 2"));
    return recommendations;
}