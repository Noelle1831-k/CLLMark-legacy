Artist* createArtists() {
    Artist *artists = (Artist*)malloc(sizeof(Artist) * 10);
    for (int i = 0; i < 10; i++) {
        artists[i].name = (char*)malloc(50 * sizeof(char));
        snprintf(artists[i].name, 50, "Artist %d", i + 1);
        artists[i].genre = (char*)malloc(50 * sizeof(char));
        snprintf(artists[i].genre, 50, "Genre %d", i % 5 + 1);
        artists[i].availability = 1; 
    }
    return artists;
}