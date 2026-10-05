void display_playlist(Playlist *playlist) {
    printf("Playlist: %s\n", playlist->name);
    for (int i = 0; i < playlist->song_count; i++) {
        display_song(&playlist->songs[i]);
    }
}