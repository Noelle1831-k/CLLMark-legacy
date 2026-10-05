int main() {
    Database db;
    db.loadMovies();
    db.loadUsers();
    RecommendationEngine engine(db);
    int userId;
    cout << "Enter User ID for recommendations: ";
    cin >> userId;
    vector<Movie> recommendations = engine.getRecommendations(userId);
    if (recommendations.empty()) {
        cout << "No recommendations available. Please check the User ID or user preferences." << endl;
    } else {
        cout << "Recommended Movies:" << endl;
        for (size_t i = 0; i < recommendations.size(); i++) {
            cout << recommendations[i].getTitle() << " (" << recommendations[i].getGenre() << "), Rating: " << recommendations[i].getRating() << endl;
        }
    }
    return 0;
}