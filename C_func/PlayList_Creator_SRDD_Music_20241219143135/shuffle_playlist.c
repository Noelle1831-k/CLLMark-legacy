void shuffle_playlist(Playlist *playlist) {
    srand(time(NULL));
    for (int i = 0; i < playlist->song_count; i++) {
        int j = rand() % playlist->song_count;
        Song temp = playlist->songs[i];
        playlist->songs[i] = playlist->songs[j];
        playlist->songs[j] = temp;
    }
}