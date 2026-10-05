void add_song_to_library(Library *library, Song song) {
    if (library->song_count < MAX_SONGS) {
        library->songs[library->song_count++] = song;
    } else {
        printf("Error: Library is full. Cannot add more songs.\n");
    }
}