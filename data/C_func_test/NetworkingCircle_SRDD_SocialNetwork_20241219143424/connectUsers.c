void connectUsers() {
    if (loggedInUserIndex == -1) {
        printf("No user logged in.\n");
        return;
    }
    printf("Connecting users within the same industry...\n");
    User *currentUser = &users[loggedInUserIndex];
    for (int i = 0; i < userCount; i++) {
        if (i != loggedInUserIndex && strcmp(currentUser->industry, users[i].industry) == 0) {
            int alreadyConnected = 0;
            for (int j = 0; j < currentUser->connectionCount; j++) {
                if (strcmp(currentUser->connections[j], users[i].username) == 0) {
                    alreadyConnected = 1;
                    break;
                }
            }
            if (!alreadyConnected) {
                strcpy(currentUser->connections[currentUser->connectionCount++], users[i].username);
                printf("Connected with %s\n", users[i].username);
            }
        }
    }
}