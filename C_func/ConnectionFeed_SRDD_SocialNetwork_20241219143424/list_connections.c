void list_connections(const char *user) {
    printf("Connections for %s:\n", user);
    for (int i = 0; i < connection_count; i++) {
        if (strcmp(connections[i].user1, user) == 0) {
            printf("- %s\n", connections[i].user2);
        } else if (strcmp(connections[i].user2, user) == 0) {
            printf("- %s\n", connections[i].user1);
        }
    }
}