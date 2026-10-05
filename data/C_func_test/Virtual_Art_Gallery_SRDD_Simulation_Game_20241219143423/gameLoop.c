void gameLoop() {
    int choice;
    while (1) {
        printf("\n====== Virtual Art Gallery Menu ======\n");
        printf("1. Create Gallery\n");
        printf("2. Add Artwork\n");
        printf("3. View Galleries\n");
        printf("4. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createGallery();
                break;
            case 2:
                addArtwork();
                break;
            case 3:
                displayGalleries();
                break;
            case 4:
                saveGalleriesToFile("galleries.dat");
                saveArtworksToFile("artworks.dat");
                savePlayersToFile("players.dat");
                printf("Game saved. Exiting...\n");
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}