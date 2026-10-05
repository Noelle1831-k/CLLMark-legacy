void adjust_playlist_volume(Playlist *playlist, float volume) {
    for (int i = 0; i < playlist->song_count; i++) {
        apply_volume_control(&playlist->songs[i], volume);
    }
}