void add_connection(const char *user1, const char *user2) {
    if (connection_count >= MAX_USERS) {
        printf("Error: Maximum connections reached!\n");
        return;
    }
    strcpy(connections[connection_count].user1, user1);
    strcpy(connections[connection_count].user2, user2);
    connection_count++;
    printf("Connection added between %s and %s.\n", user1, user2);
}