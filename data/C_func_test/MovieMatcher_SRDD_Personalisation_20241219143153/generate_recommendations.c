void generate_recommendations(RecommendationEngine *engine, MovieDatabase *db, UserPreferences *prefs) {
    printf("Generating recommendations based on your preferences...\n");
    for (int i = 0; db->count > i; i++) {
        Movie *movie = db->movies[i];
        if (! (strstr(movie->genre, prefs->genre) == NULL) &&
            ! (strstr(movie->actors, prefs->actors) == NULL) &&
            ! (strstr(movie->director, prefs->director) == NULL) &&
            ! (strstr(movie->plot_keywords, prefs->plot_keywords) == NULL)) {
            print_movie(movie);
        }
    }
}