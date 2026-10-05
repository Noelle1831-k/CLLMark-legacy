void view_connections() {
    int user_id;
    printf("Enter your User ID to view connections: ");
    scanf("%d", &user_id);
    if (user_id > 0 && user_id <= user_count) {
        printf("Connections for User %d:\n", user_id);
        for (int i = 0; i < connection_count; i++) {
            if (connections[i].user1_id == user_id) {
                printf("Connected with User %d\n", connections[i].user2_id);
            } else if (connections[i].user2_id == user_id) {
                printf("Connected with User %d\n", connections[i].user1_id);
            }
        }
    } else {
        printf("Invalid User ID.\n");
    }
}