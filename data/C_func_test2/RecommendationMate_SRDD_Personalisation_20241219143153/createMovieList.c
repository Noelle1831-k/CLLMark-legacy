MovieList* createMovieList(int size) {
    MovieList *list = (MovieList *)malloc(sizeof(MovieList));
    list->movies = (Movie **)malloc(size * sizeof(Movie *));
    list->count = 0;
    return list;
}