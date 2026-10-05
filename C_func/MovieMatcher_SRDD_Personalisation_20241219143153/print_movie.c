void print_movie(const Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Genre: %s\n", movie->genre);
    printf("Actors: %s\n", movie->actors);
    printf("Director: %s\n", movie->director);
    printf("Plot Keywords: %s\n", movie->plot_keywords);
}