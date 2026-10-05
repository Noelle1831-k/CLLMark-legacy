void save_playlist(const char *filename, Playlist *playlist) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error: Could not save playlist.\n");
        return;
    }
    fwrite(playlist, sizeof(Playlist), 1, file);
    fclose(file);
    printf("Playlist saved successfully.\n");
}