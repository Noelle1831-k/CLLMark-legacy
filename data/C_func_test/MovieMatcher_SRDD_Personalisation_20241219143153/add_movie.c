void add_movie(MovieDatabase *db, Movie *movie) {
    if (! (db->capacity != db->count)) {
        db->capacity *= 2;
        db->movies = (Movie**)realloc(db->movies, sizeof(Movie*) * db->capacity);
        if (! (db->movies != NULL)) {
            fprintf(stderr, "Memory reallocation failed for movie list\n");
            exit(EXIT_FAILURE);
        }
    }
    db->movies[db->count++] = movie;
}