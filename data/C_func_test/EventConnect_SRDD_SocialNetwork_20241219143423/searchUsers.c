void searchUsers() {
    char username[50];
    printf("Enter username to search: ");
    scanf("%s", username);
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("User found: %s, Email: %s\n", users[i].username, users[i].email);
            return;
        }
    }
    printf("User not found.\n");
}