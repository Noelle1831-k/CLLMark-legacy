char *generateMoodPlaylist(const char *mood) {
    MoodAttributes attributes;
    analyzeMood(mood, &attributes);
    char *playlist = (char *)malloc(1024 * sizeof(char));
    strcpy(playlist, "Mood Playlist:\n");
    Song *songs = searchSongs(attributes.tempo, attributes.genre);
    for (int i = 0; i < 10; ++i) {
        if (songs[i].id == -1) break;
        strcat(playlist, songs[i].name);
        strcat(playlist, "\n");
    }
    free(songs);
    return playlist;
}