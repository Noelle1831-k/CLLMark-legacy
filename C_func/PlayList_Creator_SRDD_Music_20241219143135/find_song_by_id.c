Song *find_song_by_id(Library *library, int song_id) {
    for (int i = 0; i < library->song_count; i++) {
        if (library->songs[i].id == song_id) {
            return &library->songs[i];
        }
    }
    return NULL;
}