void freeMovie(Movie *movie) {
    free(movie->title);
    free(movie);
}