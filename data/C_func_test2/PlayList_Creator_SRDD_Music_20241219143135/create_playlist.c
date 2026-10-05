void create_playlist(Library *library, const char *name, const char *tags[]) {
    if (library->playlist_count < MAX_PLAYLISTS) {
        Playlist playlist;
        playlist.id = library->playlist_count + 1;
        strcpy(playlist.name, name);
        playlist.song_count = 0;
        for (int i = 0; tags[i] != NULL && i < 10; i++) {
            strcpy(playlist.tags[i], tags[i]);
        }
        library->playlists[library->playlist_count++] = playlist;
    } else {
        printf("Error: Maximum number of playlists reached.\n");
    }
}