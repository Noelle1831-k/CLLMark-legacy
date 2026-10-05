void free_movie_database(MovieDatabase *db) {
    for (int i = 0; i < db->count; i++) {
        free(db->movies[i]);
    }
    free(db->movies);
    free(db);
}