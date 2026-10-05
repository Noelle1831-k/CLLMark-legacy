Genre* createGenres() {
    Genre *genres = (Genre*)malloc(sizeof(Genre) * 5);
    const char* genreNames[] = {"Rock", "Pop", "Jazz", "Classical", "Electronic"};
    for (int i = 0; i < 5; i++) {
        genres[i].name = (char*)malloc(50 * sizeof(char));
        snprintf(genres[i].name, 50, "%s", genreNames[i]);
    }
    return genres;
}