void WellnessTracker::displayResults() {
    cout << "Your wellness insights and recommendations:" << endl;
    analyzer.displayAnalysis();
    recommender.displayRecommendations();
}