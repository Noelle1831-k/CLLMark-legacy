int main(void) {
    cout << "Welcome to MovieMatcher!" << endl;
    MovieDatabase movieDB;
    movieDB.addMovie(Movie("Inception", "Sci-Fi", "Christopher Nolan", {"Leonardo DiCaprio"}, {"dream", "heist"}));
    movieDB.addMovie(Movie("The Dark Knight", "Action", "Christopher Nolan", {"Christian Bale"}, {"hero", "justice"}));
    movieDB.addMovie(Movie("Titanic", "Romance", "James Cameron", {"Leonardo DiCaprio", "Kate Winslet"}, {"ship", "love"}));
    movieDB.addMovie(Movie("Interstellar", "Sci-Fi", "Christopher Nolan", {"Matthew McConaughey", "Anne Hathaway"}, {"space", "time"}));
    movieDB.addMovie(Movie("Avatar", "Sci-Fi", "James Cameron", {"Sam Worthington", "Zoe Saldana"}, {"alien", "planet"}));
    UserPreferences userPrefs;
    string genre, actor, director, keyword;
    cout << "Enter your favorite genre: ";
    cin >> genre;
    userPrefs.addGenre(genre);
    cout << "Enter your favorite actor: ";
    cin >> actor;
    userPrefs.addActor(actor);
    cout << "Enter your favorite director: ";
    cin >> director;
    userPrefs.addDirector(director);
    cout << "Enter a plot keyword you like: ";
    cin >> keyword;
    userPrefs.addKeyword(keyword);
    RecommendationEngine engine;
    vector<Movie> recommendations = engine.generateRecommendations(userPrefs, movieDB);
    cout << "\nRecommended Movies for You:" << endl;
    if (recommendations.empty()) {
        cout << "No movies found matching your preferences. Please try again with different inputs." << endl;
    } else {
        for (int i = 0; ; ) {
            if (!((i <= recommendations.size() && i != recommendations.size()))) {
                break;
            }
            recommendations[i].display();
            ++i;
        }
    }
    return 0;
}