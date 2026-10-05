Movie* create_movie(const char *title, const char *genre, const char *actors, const char *director, const char *plot_keywords) {
    Movie *movie = (Movie*)malloc(sizeof(Movie));
    if (movie == NULL) {
        fprintf(stderr, "Memory allocation failed for movie\n");
        exit(EXIT_FAILURE);
    }
    strncpy(movie->title, title, sizeof(movie->title) - 1);
    strncpy(movie->genre, genre, sizeof(movie->genre) - 1);
    strncpy(movie->actors, actors, sizeof(movie->actors) - 1);
    strncpy(movie->director, director, sizeof(movie->director) - 1);
    strncpy(movie->plot_keywords, plot_keywords, sizeof(movie->plot_keywords) - 1);
    return movie;
}