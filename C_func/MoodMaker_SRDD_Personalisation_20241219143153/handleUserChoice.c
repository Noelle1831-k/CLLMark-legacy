void handleUserChoice(int choice) {
    char mood[50];
    switch (choice) {
        case 1:
            printf("Enter your mood (e.g., Happy, Sad, Energetic, Relaxed): ");
            scanf("%s", mood);
            char *playlist = generateMoodPlaylist(mood);
            printf("Generated Playlist: \n%s\n", playlist);
            strcpy(currentPlaylist, playlist); 
            free(playlist);
            break;
        case 2:
            saveCurrentPlaylist();
            break;
        case 3:
            shareCurrentPlaylist();
            break;
        case 4:
            break;
        default:
            printf("Invalid choice! Please try again.\n");
    }
}