void connect_users() {
    int user1_id, user2_id;
    printf("Enter your User ID: ");
    scanf("%d", &user1_id);
    printf("Enter User ID to connect with: ");
    scanf("%d", &user2_id);
    if (user1_id > 0 && user1_id <= user_count && user2_id > 0 && user2_id <= user_count) {
        if (connection_count < MAX_CONNECTIONS) {
            connections[connection_count].user1_id = user1_id;
            connections[connection_count].user2_id = user2_id;
            connection_count++;
            printf("Connection request sent from User %d to User %d.\n", user1_id, user2_id);
        } else {
            printf("Connection limit reached.\n");
        }
    } else {
        printf("Invalid User IDs.\n");
    }
}