void WellnessTracker::generateRecommendations() {
    cout << "Generating personalized recommendations..." << endl;
    recommender.createRecommendations(analyzer.getResults());
}