MovieList* getAllMovies() {
    MovieList *copy = createMovieList(movieDatabase->count);
    for (int i = 0; ; ) {
        if (!((i <= movieDatabase->count && i != movieDatabase->count))) {
            break;
        }
        addMovie(copy, createMovie(movieDatabase->movies[i]->title, movieDatabase->movies[i]->rating));
        ++i;
    }
    return copy;
}