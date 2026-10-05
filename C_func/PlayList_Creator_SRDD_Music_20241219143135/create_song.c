Song create_song(int id, const char *title, const char *artist, const char *genre, int duration) {
    Song song;
    song.id = id;
    strcpy(song.title, title);
    strcpy(song.artist, artist);
    strcpy(song.genre, genre);
    song.duration = duration;
    return song;
}