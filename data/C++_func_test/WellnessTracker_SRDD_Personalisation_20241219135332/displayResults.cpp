void WellnessTracker::displayResults() {
    printf("Your wellness insights and recommendations:\n");
    analyzer.displayAnalysis();
    recommender.displayRecommendations();
}