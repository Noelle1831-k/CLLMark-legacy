void RecommendationEngine::explainRecommendations(vector<string>& recommendations) {
    cout << "Explaining recommendations..." << endl;
    for (int i = 0; i < recommendations.size(); i++) {
        cout << "Recommendation: " << recommendations[i] << endl;
    }
}