void display_network(const Network *network) {
    printf("Network Users:\n");
    for (int i = 0; i < network->user_count; i++) {
        printf("User %d:\n", i + 1);
        display_user(network->users[i]);
    }
}