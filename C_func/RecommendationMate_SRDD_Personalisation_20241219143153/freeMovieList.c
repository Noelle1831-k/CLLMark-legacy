void freeMovieList(MovieList *list) {
    for (int i = 0; i < list->count; i++) {
        freeMovie(list->movies[i]);
    }
    free(list->movies);
    free(list);
}