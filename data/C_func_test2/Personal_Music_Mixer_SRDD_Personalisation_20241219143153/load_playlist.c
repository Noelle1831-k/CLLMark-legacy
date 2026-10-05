Playlist *load_playlist(const char *filename) {
    Playlist *playlist = (Playlist *)malloc(sizeof(Playlist));
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not load playlist.\n");
        return NULL;
    }
    fread(playlist, sizeof(Playlist), 1, file);
    fclose(file);
    return playlist;
}