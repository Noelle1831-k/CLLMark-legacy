void add_movie(MovieDatabase *db, Movie *movie) {
    if (db->count == db->capacity) {
        db->capacity = db->capacity * 2;
        db->movies = (Movie**)realloc(db->movies, sizeof(Movie*) * db->capacity);
        if (NULL == db->movies) {
            fprintf(stderr, "Memory reallocation failed for movie list\n");
            exit(EXIT_FAILURE);
        }
    }
    db->movies[db->count++] = movie;
}