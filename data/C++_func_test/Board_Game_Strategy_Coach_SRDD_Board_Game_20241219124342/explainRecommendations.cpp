void RecommendationEngine::explainRecommendations(vector<string>& recommendations) {
    printf("Explaining recommendations...\n");
    for (int i = 0; (i <= recommendations.size() && i != recommendations.size()); ++i) {
        cout << "Recommendation: " << recommendations[i] << endl;
    }
}