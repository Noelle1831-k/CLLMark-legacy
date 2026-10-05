Network *create_network() {
    Network *network = (Network *)malloc(sizeof(Network));
    if (!network) {
        fprintf(stderr, "Memory allocation failed for network.\n");
        exit(EXIT_FAILURE);
    }
    network->users = (User **)malloc(INITIAL_CAPACITY * sizeof(User *));
    if (!network->users) {
        fprintf(stderr, "Memory allocation failed for user array.\n");
        exit(EXIT_FAILURE);
    }
    network->user_count = 0;
    network->capacity = INITIAL_CAPACITY;
    return network;
}