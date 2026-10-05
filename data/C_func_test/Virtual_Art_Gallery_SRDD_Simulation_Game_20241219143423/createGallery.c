void createGallery() {
    if (galleryCount >= MAX_GALLERIES) {
        printf("Cannot create more galleries. Maximum limit reached.\n");
        return;
    }
    printf("Enter gallery name: ");
    char *name = (char*)malloc(sizeof(char) * MAX_NAME_LENGTH);
    scanf(" %[^\n]%*c", name);
    strcpy(galleries[galleryCount].name, name);
    galleries[galleryCount].artworkCount = 0;
    galleryCount++;
    printf("Gallery '%s' created successfully.\n", name);
}