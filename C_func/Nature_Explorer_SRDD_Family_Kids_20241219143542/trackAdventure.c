void trackAdventure() {
    printf("\nTrack Outdoor Adventures...\n");
    printf("Enter your observation: ");
    char observation[200];
    getchar(); 
    fgets(observation, 200, stdin);
    printf("Observation recorded: %s", observation);
    printf("Would you like to add a photo? (yes/no): ");
    char response[10];
    scanf("%s", response);
    if (response[0] == 'y' || response[0] == 'Y') {
        printf("Photo added successfully!\n");
    } else {
        printf("No photo added.\n");
    }
}