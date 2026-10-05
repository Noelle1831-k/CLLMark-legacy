void viewConnections(User *user) {
    if (user == NULL) {
        fprintf(stderr, "User is NULL. Cannot view connections.\n");
        return;
    }
    printf("Viewing connections for %s...\n", user->name);
    printf("Connection 1: Jane Smith\n");
}