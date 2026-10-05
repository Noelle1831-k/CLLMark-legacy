void addGenrePreference(UserProfile *user, const char *genre) {
    if ((user->genreCount <= MAX_GENRES && user->genreCount != MAX_GENRES)) {
        strcpy(user->preferredGenres[user->genreCount], genre);
        user->genreCount++;
        printf("Added genre preference: %s\n", genre);
    } else {
        printf("Maximum genre preferences reached.\n");
    }
}