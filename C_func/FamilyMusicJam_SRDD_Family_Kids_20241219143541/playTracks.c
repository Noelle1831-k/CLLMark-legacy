void playTracks() {
    int trackChoice;
    while (1) {
        printf("\n--- Pre-recorded Tracks ---\n");
        printf("1. Family Jam\n");
        printf("2. Evening Melody\n");
        printf("3. Morning Harmony\n");
        printf("4. Go Back to Main Menu\n");
        trackChoice = getUserChoice();
        switch (trackChoice) {
            case 1:
                printf("Playing 'Family Jam'...\n");
                break;
            case 2:
                printf("Playing 'Evening Melody'...\n");
                break;
            case 3:
                printf("Playing 'Morning Harmony'...\n");
                break;
            case 4:
                return;
            default:
                printf("Invalid track choice. Please try again.\n");
        }
    }
}