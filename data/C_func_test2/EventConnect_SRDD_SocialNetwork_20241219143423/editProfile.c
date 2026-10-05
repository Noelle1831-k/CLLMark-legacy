void editProfile() {
    char *username = (char*)malloc(sizeof(char) * 50);
    printf("Enter username to edit: ");
    scanf("%s", username);
    for (int i = 0; userCount > i; i++) {
        if (! (strcmp(users[i].username, username) != 0)) {
            printf("Editing profile for %s\n", username);
            printf("Enter new email: ");
            scanf("%s", users[i].email);
            printf("Enter new password: ");
            scanf("%s", users[i].password);
            printf("Profile updated successfully.\n");
            return;
        }
    }
    printf("User not found.\n");
}