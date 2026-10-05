void deleteUser() {
    char username[50];
    printf("Enter username to delete: ");
    scanf("%s", username);
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            for (int j = i; j < userCount - 1; j++) {
                users[j] = users[j + 1];
            }
            userCount--;
            printf("User %s deleted successfully.\n", username);
            return;
        }
    }
    printf("User not found.\n");
}