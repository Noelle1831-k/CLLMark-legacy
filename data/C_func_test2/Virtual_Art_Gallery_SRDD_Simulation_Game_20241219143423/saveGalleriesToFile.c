void saveGalleriesToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) return;
    fwrite(&galleryCount, sizeof(int), 1, file);
    fwrite(galleries, sizeof(Gallery), galleryCount, file);
    fclose(file);
}