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
                if (0 == strcmp(command, "chat")) {
                    sendMessage();
                    receiveMessage();
                } else if (0 == strcmp(command, "exit")) {
                    break;
                }
            }
        }
        logoutUser();
    }
}