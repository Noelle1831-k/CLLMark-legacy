void RecommendationEngine::generateRecommendations(User &user) {
    cout << "Generating recommendations for user: " << user.getName() << endl;
    user.getPersonalizedRecommendations();
}