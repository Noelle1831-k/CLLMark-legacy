void saveArtworksToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) return;
    fwrite(&artworkCount, sizeof(int), 1, file);
    fwrite(artworks, sizeof(Artwork), artworkCount, file);
    fclose(file);
}