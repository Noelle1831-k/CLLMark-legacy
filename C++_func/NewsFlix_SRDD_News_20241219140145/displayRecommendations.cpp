void NewsRecommendationEngine::displayRecommendations(const User& user) {
    vector<NewsArticle> recommendations = generateRecommendations(user);
    cout << "Recommended Articles:" << endl;
    for (const auto& article : recommendations) {
        cout << article.getTitle() << endl;
    }
}