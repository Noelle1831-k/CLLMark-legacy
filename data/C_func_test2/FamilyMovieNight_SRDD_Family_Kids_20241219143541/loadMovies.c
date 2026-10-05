void loadMovies() {
    printf("Loading movies...\n");
    strcpy(movieLibrary[0].title, "The Great Adventure");
    strcpy(movieLibrary[0].genre, "Adventure");
    movieLibrary[0].duration = 120;
    movieCount++;
    printf("Movies loaded: %d\n", movieCount);
}