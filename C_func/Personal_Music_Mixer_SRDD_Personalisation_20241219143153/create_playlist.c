Playlist *create_playlist(const char *name) {
    Playlist *playlist = (Playlist *)malloc(sizeof(Playlist));
    strcpy(playlist->name, name);
    playlist->song_count = 0;
    return playlist;
}