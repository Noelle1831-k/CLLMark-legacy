void add_connection(User* user, const char* connection_name) {
    if (user->num_connections >= MAX_CONNECTIONS) {
        printf("Cannot add more connections for user %s.\n", user->name);
        return;
    }
    strcpy(user->connections[user->num_connections++], connection_name);
}