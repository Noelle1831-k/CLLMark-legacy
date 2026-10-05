int main() {
    Database *db = createDatabase(MAX_USERS);
    char command[50];
    while (1) {
        printf("Enter command (create, request, message, search, exit): ");
        scanf("%s", command);
        if (strcmp(command, "create") == 0) {
            char username[50];
            printf("Enter username: ");
            scanf("%s", username);
            User *user = createUser(username);
            addUser(db, user);
        } else if (strcmp(command, "request") == 0) {
            char username[50], type[50];
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter request type: ");
            scanf("%s", type);
            Request *req = createRequest(type);
            addRequestToUser(db, username, req);
        } else if (strcmp(command, "message") == 0) {
            char sender[50], receiver[50], content[100];
            printf("Enter sender username: ");
            scanf("%s", sender);
            printf("Enter receiver username: ");
            scanf("%s", receiver);
            printf("Enter message content: ");
            scanf(" %[^\n]s", content);
            sendMessage(db, sender, receiver, content);
        } else if (strcmp(command, "search") == 0) {
            char skill[50];
            printf("Enter skill to search: ");
            scanf("%s", skill);
            searchRequests(db, skill);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    freeDatabase(db);
    return 0;
}