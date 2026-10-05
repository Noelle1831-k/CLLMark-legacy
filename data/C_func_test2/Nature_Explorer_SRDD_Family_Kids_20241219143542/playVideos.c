void playVideos() {
    printf("\nEducational Videos...\n");
    printf("1. Wildlife Conservation\n");
    printf("2. The Life of a Tree\n");
    printf("3. Ocean Ecosystems\n");
    printf("Enter the video you want to watch: ");
    int choice;
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Returning to main menu.\n");
        while (getchar() != '\n'); 
        return;
    }
    switch (choice) {
        case 1:
            printf("Playing 'Wildlife Conservation'...\n");
            break;
        case 2:
            printf("Playing 'The Life of a Tree'...\n");
            break;
        case 3:
            printf("Playing 'Ocean Ecosystems'...\n");
            break;
        default:
            printf("Invalid choice. Returning to main menu.\n");
    }
}