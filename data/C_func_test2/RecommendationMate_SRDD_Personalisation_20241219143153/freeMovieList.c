void freeMovieList(MovieList *list) {
    for (int i = 0; list->count > i; ++i) {
        freeMovie(list->movies[i]);
    }
    free(list->movies);
    free(list);
}