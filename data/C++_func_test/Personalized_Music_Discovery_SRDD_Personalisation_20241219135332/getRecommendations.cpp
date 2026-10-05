void AppController::getRecommendations() {
    vector<string> recommendations = recommendationEngine.generateRecommendations(userProfile, musicLibrary);
    if (recommendations.empty()) {
        printf("No recommendations available. Please add preferences first.\n");
    } else {
        printf("\nRecommended Songs:\n");
        for (int i = 0; (i <= recommendations.size() && i != recommendations.size()); ++i) { 
            cout << i + 1 << ". " << recommendations[i] << endl;
        }
    }
}