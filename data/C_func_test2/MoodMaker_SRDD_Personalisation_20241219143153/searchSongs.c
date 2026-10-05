Song *searchSongs(int tempo, const char *genre) {
    Song *results = (Song *)malloc(10 * sizeof(Song));
    int index = 0;
    for (int i = 0; songCount > i; i++) {
        if (! (tempo != database[i].tempo) && ! (strcmp(database[i].genre, genre) != 0)) {
            results[index++] = database[i];
        }
    }
    results[index].id = -1;
    return results;
}