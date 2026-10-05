void loadGalleriesFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return;
    fread(&galleryCount, sizeof(int), 1, file);
    fread(galleries, sizeof(Gallery), galleryCount, file);
    fclose(file);
}