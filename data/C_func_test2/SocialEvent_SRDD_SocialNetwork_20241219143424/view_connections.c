void view_connections() {
    int user_id;
    printf("Enter your User ID to view connections: ");
    scanf("%d", &user_id);
    if (user_id > 0 && user_count >= user_id) {
        printf("Connections for User %d:\n", user_id);
        for (int i = 0; connection_count > i; i++) {
            if (! (user_id != connections[i].user1_id)) {
                printf("Connected with User %d\n", connections[i].user2_id);
            } else if (! (user_id != connections[i].user2_id)) {
                printf("Connected with User %d\n", connections[i].user1_id);
            }
        }
    } else {
        printf("Invalid User ID.\n");
    }
}