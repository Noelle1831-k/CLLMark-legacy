vector<Movie> RecommendationEngine::getRecommendations(int userId) {
    vector<Movie> recommendations;
    auto userOpt = db.getUser(userId);
    if (!userOpt.has_value()) {
        cout << "User not found. Please check the User ID." << endl;
        return recommendations; 
    }
    User user = userOpt.value();
    vector<string> preferences = user.getPreferences();
    vector<Movie> movies = db.getMovies();
    for (size_t i = 0; i < movies.size(); i++) {
        for (size_t j = 0; j < preferences.size(); j++) {
            if (movies[i].getGenre() == preferences[j]) {
                recommendations.push_back(movies[i]);
            }
        }
    }
    return recommendations;
}