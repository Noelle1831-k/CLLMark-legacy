void displayConnections() {
    if (loggedInUserIndex == -1) {
        printf("No user logged in.\n");
        return;
    }
    User *currentUser = &users[loggedInUserIndex];
    printf("Your connections:\n");
    for (int i = 0; i < currentUser->connectionCount; i++) {
        printf("  - %s\n", currentUser->connections[i]);
    }
}