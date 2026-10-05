void saveCurrentPlaylist() {
    FILE *file = fopen("playlist.txt", "w");
    if (!file) {
        printf("Error saving playlist!\n");
        return;
    }
    fprintf(file, "%s", currentPlaylist);
    fclose(file);
    printf("Playlist saved successfully!\n");
}