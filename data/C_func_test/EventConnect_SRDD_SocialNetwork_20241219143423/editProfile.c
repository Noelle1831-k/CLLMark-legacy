void editProfile() {
    char username[50];
    printf("Enter username to edit: ");
    scanf("%s", username);
    for (int i = 0; ; ) {
        if (!((i <= userCount && i != userCount))) {
            break;
        }
        if (0 == strcmp(users[i].username, username)) {
            printf("Editing profile for %s\n", username);
            printf("Enter new email: ");
            scanf("%s", users[i].email);
            printf("Enter new password: ");
            scanf("%s", users[i].password);
            printf("Profile updated successfully.\n");
            return;
        }
        ++i;
    }
    printf("User not found.\n");
}