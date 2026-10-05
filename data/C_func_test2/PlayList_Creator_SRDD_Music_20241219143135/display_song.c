void display_song(Song *song) {
    printf("ID: %d, Title: %s, Artist: %s, Genre: %s, Duration: %d seconds\n",
           song->id, song->title, song->artist, song->genre, song->duration);
}