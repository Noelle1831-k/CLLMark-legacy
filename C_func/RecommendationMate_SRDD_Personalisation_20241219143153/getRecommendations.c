MovieList* getRecommendations(User *user) {
    MovieList *allMovies = getAllMovies();
    MovieList *recommended = createMovieList(5);
    for (int i = 0; i < allMovies->count; i++) {
        if (user->preferences[i % 10] > 2) {
            addMovie(recommended, createMovie(allMovies->movies[i]->title, allMovies->movies[i]->rating));
        }
    }
    freeMovieList(allMovies);
    return recommended;
}