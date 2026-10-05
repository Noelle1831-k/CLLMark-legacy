int startStream() {
    printf("Starting stream...\n");
    int success = 1; 
    if (success) {
        printf("Stream started successfully.\n");
        return 1;
    } else {
        printf("Failed to start stream.\n");
        return 0;
    }
}