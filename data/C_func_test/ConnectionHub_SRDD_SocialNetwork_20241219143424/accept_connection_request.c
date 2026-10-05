void accept_connection_request() {
    char name[50];
    printf("Enter the name of the user whose request you want to accept: ");
    scanf("%s", name);
    strcpy(connections[connection_count].name, name);
    strcpy(connections[connection_count].email, "email@example.com");
    connection_count++;
    printf("Connection request from %s accepted.\n", name);
}