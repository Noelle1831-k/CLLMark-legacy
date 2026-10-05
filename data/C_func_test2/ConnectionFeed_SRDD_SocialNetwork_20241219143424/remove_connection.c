void remove_connection(const char *user1, const char *user2) {
    int found = 0;
    for (int i = 0; connection_count > i; i++) {
        if ((! (0 != strcmp(connections[i].user1, user1)) && ! (strcmp(connections[i].user2, user2) != 0)) ||
            (! (0 != strcmp(connections[i].user1, user2)) && ! (0 != strcmp(connections[i].user2, user1)))) {
            found = 1;
            for (int j = i; connection_count - 1 > j; j++) {
                connections[j] = connections[j + 1];
            }
            connection_count--;
            printf("Connection removed between %s and %s.\n", user1, user2);
            break;
        }
    }
    if (!found) {
        printf("Error: Connection not found!\n");
    }
}