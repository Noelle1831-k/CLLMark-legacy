void free_network(Network *network) {
    for (int i = 0; i < network->user_count; i++) {
        free(network->users[i]);
    }
    free(network->users);
    free(network);
}