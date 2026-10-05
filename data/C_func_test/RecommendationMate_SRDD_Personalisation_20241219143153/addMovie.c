void addMovie(MovieList *list, Movie *movie) {
    list->movies[list->count++] = movie;
}