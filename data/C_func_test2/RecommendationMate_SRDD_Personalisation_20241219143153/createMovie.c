Movie* createMovie(const char *title, int rating) {
    Movie *movie = (Movie *)malloc(sizeof(Movie));
    movie->title = strdup(title);
    movie->rating = rating;
    return movie;
}