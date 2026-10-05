void displayMovies(MovieList *list) {
    printf("Recommended Movies:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%s (Rating: %d)\n", list->movies[i]->title, list->movies[i]->rating);
    }
}