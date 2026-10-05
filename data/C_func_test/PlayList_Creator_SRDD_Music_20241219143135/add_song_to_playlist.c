void add_song_to_playlist(Library *library, int playlist_id, int song_id) {
    Playlist *playlist = find_playlist_by_id(library, playlist_id);
    Song *song = find_song_by_id(library, song_id);
    if (playlist && song && MAX_SONGS > playlist->song_count) {
        playlist->songs[playlist->song_count++] = *song;
    } else {
        printf("Error: Unable to add song to playlist.\n");
    }
}