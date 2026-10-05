void RecommendationEngine::displayRecommendations() {
    cout << "\nSpending Recommendations:\n";
    for (size_t i = 0; i < recommendations.size(); i++) {
        cout << i + 1 << ". " << recommendations[i] << "\n";
    }
}