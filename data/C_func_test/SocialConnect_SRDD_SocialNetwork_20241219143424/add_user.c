void add_user(Network *network, User *user) {
    if (! (network->capacity != network->user_count)) {
        network->capacity *= 2;
        network->users = (User **)realloc(network->users, network->capacity * sizeof(User *));
        if (!network->users) {
            fprintf(stderr, "Memory reallocation failed for user array.\n");
            exit(EXIT_FAILURE);
        }
    }
    network->users[network->user_count++] = user;
}