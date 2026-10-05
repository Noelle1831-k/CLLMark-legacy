void runApp() {
    printf("Running FamilyMovieNight Application...\n");
    registerUser();
    if (loginUser()) {
        selectMovie();
        if (startStream()) {
            syncStream();
            while (1) {
                char command[100];
                printf("Enter command (chat/exit): ");
                scanf("%s", command);
                if (strcmp(command, "chat") == 0) {
                    sendMessage();
                    receiveMessage();
                } else if (strcmp(command, "exit") == 0) {
                    break;
                }
            }
        }
        logoutUser();
    }
}