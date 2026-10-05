void addConnection(User *user, const char *name) {
    if (user == NULL) {
        fprintf(stderr, "User is NULL. Cannot add connection.\n");
        return;
    }
    Connection *connection = (Connection*)malloc(sizeof(Connection));
    if (connection == NULL) {
        fprintf(stderr, "Memory allocation failed for connection.\n");
        return;
    }
    strcpy(connection->name, name);
    connection->id = generateID();
    printf("%s added to %s's connections.\n", connection->name, user->name);
    free(connection);
}