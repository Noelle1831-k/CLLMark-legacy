void addArtwork() {
    if (artworkCount >= MAX_ARTWORKS) {
        printf("Cannot add more artworks. Maximum limit reached.\n");
        return;
    }
    Artwork newArtwork;
    printf("Enter artwork title: ");
    scanf(" %[^\n]%*c", newArtwork.title);
    printf("Enter artist name: ");
    scanf(" %[^\n]%*c", newArtwork.artist);
    printf("Enter year of creation: ");
    scanf("%d", &newArtwork.year);
    artworks[artworkCount++] = newArtwork;
    printf("Artwork '%s' by '%s' added successfully.\n", newArtwork.title, newArtwork.artist);
}