void view_connections() {
    printf("\n--- Connections ---\n");
    for (int i = 0; i < connection_count; i++) {
        printf("Name: %s, Email: %s\n", connections[i].name, connections[i].email);
    }
}