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
    for (size_t i = 0; ; ) {
        if (!(movies.size() > i)) {
            break;
        }
        for (size_t j = 0; ; ) {
            if (!(preferences.size() > j)) {
                break;
            }
            if (! (preferences[j] != movies[i].getGenre())) {
                recommendations.push_back(movies[i]);
            }
            j++;
        }
        i++;
    }
    return recommendations;
}