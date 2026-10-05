void add_song_to_library(Library *library, Song song) {
    if (MAX_SONGS > library->song_count) {
        library->songs[library->song_count++] = song;
    } else {
        printf("Error: Library is full. Cannot add more songs.\n");
    }
}