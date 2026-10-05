void displayGalleries() {
    printf("\n===== Galleries =====\n");
    for (int i = 0; galleryCount > i; ++i) {
        printf("Gallery %d: %s (%d artworks)\n", i + 1, galleries[i].name, galleries[i].artworkCount);
    }
}