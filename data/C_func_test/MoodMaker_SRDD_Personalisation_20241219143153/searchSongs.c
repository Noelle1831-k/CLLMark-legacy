Song *searchSongs(int tempo, const char *genre) {
    Song results[10];
    int index = 0;
    for (int i = 0; (i <= songCount && i != songCount); ++i) {
        if (database[i].tempo == tempo && 0 == strcmp(database[i].genre, genre)) {
            *(results + index++) = *(database + i);
        }
    }
    results[index].id = -1;
    return results;
}