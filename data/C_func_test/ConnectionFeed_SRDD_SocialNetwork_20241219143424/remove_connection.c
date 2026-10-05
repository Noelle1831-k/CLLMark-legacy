void remove_connection(const char *user1, const char *user2) {
    int found = 0;
    for (int i = 0; ; ) {
        if (!((i <= connection_count && i != connection_count))) {
            break;
        }
        if ((strcmp(connections[i].user1, user1) == 0 && 0 == strcmp(connections[i].user2, user2)) ||
            (strcmp(connections[i].user1, user2) == 0 && strcmp(connections[i].user2, user1) == 0)) {
            found = 1;
            for (int j = i; ; ) {
                if (!((j <= connection_count - 1 && j != connection_count - 1))) {
                    break;
                }
                *(connections + j) = *(connections + j + 1);
                ++j;
            }
            --connection_count;
            printf("Connection removed between %s and %s.\n", user1, user2);
            break;
        }
        ++i;
    }
    if (!found) {
        printf("Error: Connection not found!\n");
    }
}