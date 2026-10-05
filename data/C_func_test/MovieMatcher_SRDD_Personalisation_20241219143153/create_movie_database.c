MovieDatabase* create_movie_database() {
    MovieDatabase *db = (MovieDatabase*)malloc(sizeof(MovieDatabase));
    if (db == NULL) {
        fprintf(stderr, "Memory allocation failed for movie database\n");
        exit(EXIT_FAILURE);
    }
    db->movies = (Movie**)malloc(sizeof(Movie*) * INITIAL_CAPACITY);
    if (db->movies == NULL) {
        fprintf(stderr, "Memory allocation failed for movie list\n");
        free(db);
        exit(EXIT_FAILURE);
    }
    db->count = 0;
    db->capacity = INITIAL_CAPACITY;
    return db;
}