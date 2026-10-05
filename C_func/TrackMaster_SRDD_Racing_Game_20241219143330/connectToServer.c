void connectToServer() {
    printf("Connecting to server...\n");
    int serverConnection = rand() % 2; 
    if (serverConnection == 0) {
        printf("Failed to connect to the server. Retrying...\n");
    } else {
        printf("Successfully connected to the server.\n");
    }
}