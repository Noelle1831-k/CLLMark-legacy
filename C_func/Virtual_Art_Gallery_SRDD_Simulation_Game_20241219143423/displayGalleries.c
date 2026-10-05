void displayGalleries() {
    printf("\n===== Galleries =====\n");
    for (int i = 0; i < galleryCount; i++) {
        printf("Gallery %d: %s (%d artworks)\n", i + 1, galleries[i].name, galleries[i].artworkCount);
    }
}