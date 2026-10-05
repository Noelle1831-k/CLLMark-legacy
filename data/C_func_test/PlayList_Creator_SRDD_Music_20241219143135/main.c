int main() {
    Library library;
    initialize_library(&library);
    Song song1 = create_song(1, "Song A", "Artist X", "Pop", 200);
    Song song2 = create_song(2, "Song B", "Artist Y", "Rock", 180);
    Song song3 = create_song(3, "Song C", "Artist Z", "Jazz", 240);
    Song song4 = create_song(4, "Song D", "Artist W", "Classical", 300);
    add_song_to_library(&library, song1);
    add_song_to_library(&library, song2);
    add_song_to_library(&library, song3);
    add_song_to_library(&library, song4);
    const char *tags1[] = {"Chill", "Mood", NULL};
    const char *tags2[] = {"Workout", "Energy", NULL};
    create_playlist(&library, "My Chill Playlist", tags1);
    create_playlist(&library, "Workout Playlist", tags2);
    add_song_to_playlist(&library, 1, 1);
    add_song_to_playlist(&library, 1, 2);
    add_song_to_playlist(&library, 2, 3);
    add_song_to_playlist(&library, 2, 4);
    Playlist *playlist1 = find_playlist_by_id(&library, 1);
    Playlist *playlist2 = find_playlist_by_id(&library, 2);
    printf("\n--- Displaying Playlists ---\n");
    display_playlist(playlist1);
    display_playlist(playlist2);
    printf("\n--- Reordering Songs in Playlist 1 ---\n");
    reorder_playlist(playlist1, 1, 0);
    display_playlist(playlist1);
    printf("\n--- Shuffling Playlist 2 ---\n");
    shuffle_playlist(playlist2);
    display_playlist(playlist2);
    printf("\n--- Searching for Song by ID ---\n");
    Song *searched_song = find_song_by_id(&library, 3);
    if (searched_song) {
        printf("Found Song:\n");
        display_song(searched_song);
    } else {
        printf("Song not found.\n");
    }
    return 0;
}