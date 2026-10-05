void display_playlist(Playlist *playlist) {
    if (!playlist) {
        printf("No playlist loaded.\n");
        return;
    }
    printf("Playlist: %s\n", playlist->name);
    for (int i = 0; i < playlist->song_count; i++) {
        printf("%d. %s\n", i + 1, playlist->songs[i].title);
    }
}