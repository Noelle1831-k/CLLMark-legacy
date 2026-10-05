Playlist *find_playlist_by_id(Library *library, int playlist_id) {
    for (int i = 0; i < library->playlist_count; i++) {
        if (library->playlists[i].id == playlist_id) {
            return &library->playlists[i];
        }
    }
    return NULL;
}