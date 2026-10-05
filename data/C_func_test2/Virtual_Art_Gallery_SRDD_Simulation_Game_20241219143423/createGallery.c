void createGallery() {
    if ((MAX_GALLERIES < galleryCount || MAX_GALLERIES == galleryCount)) {
        printf("Cannot create more galleries. Maximum limit reached.\n");
        return;
    }
    printf("Enter gallery name: ");
    char name[MAX_NAME_LENGTH];
    scanf(" %[^\n]%*c", name);
    strcpy(galleries[galleryCount].name, name);
    galleries[galleryCount].artworkCount = 0;
    ++galleryCount;
    printf("Gallery '%s' created successfully.\n", name);
}