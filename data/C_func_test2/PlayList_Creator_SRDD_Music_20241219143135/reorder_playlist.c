void reorder_playlist(Playlist *playlist, int old_position, int new_position) {
    if (old_position >= 0 && old_position < playlist->song_count &&
        new_position >= 0 && new_position < playlist->song_count) {
        Song temp = playlist->songs[old_position];
        if (old_position < new_position) {
            for (int i = old_position; i < new_position; i++) {
                playlist->songs[i] = playlist->songs[i + 1];
            }
        } else {
            for (int i = old_position; i > new_position; i--) {
                playlist->songs[i] = playlist->songs[i - 1];
            }
        }
        playlist->songs[new_position] = temp;
    } else {
        printf("Error: Invalid positions for reordering.\n");
    }
}