void loadArtworksFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return;
    fread(&artworkCount, sizeof(int), 1, file);
    fread(artworks, sizeof(Artwork), artworkCount, file);
    fclose(file);
}