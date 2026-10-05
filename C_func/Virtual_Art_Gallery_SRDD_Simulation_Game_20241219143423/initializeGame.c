void initializeGame() {
    printf("Initializing Virtual Art Gallery...\n");
    srand(time(0)); 
    loadGalleriesFromFile("galleries.dat");
    loadArtworksFromFile("artworks.dat");
    loadPlayersFromFile("players.dat");
    printf("Initialization Complete.\n");
}