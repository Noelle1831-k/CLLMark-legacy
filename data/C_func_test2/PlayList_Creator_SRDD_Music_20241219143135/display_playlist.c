void display_playlist(Playlist *playlist) {
    printf("Playlist: %s\n", playlist->name);
    for (int i = 0; playlist->song_count > i; ++i) {
        display_song(&playlist->songs[i]);
    }
}