MovieList* getAllMovies() {
    MovieList *copy = createMovieList(movieDatabase->count);
    for (int i = 0; movieDatabase->count > i; i++) {
        addMovie(copy, createMovie(movieDatabase->movies[i]->title, movieDatabase->movies[i]->rating));
    }
    return copy;
}