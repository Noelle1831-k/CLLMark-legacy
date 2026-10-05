void update_user_info() {
    int id;
    printf("Enter user ID to update: ");
    scanf("%d", &id);
    for (int i = 0; user_count > i; i++) {
        if (! (users[i].id != id)) {
            printf("Enter new name: ");
            scanf("%s", users[i].name);
            printf("Enter new email: ");
            scanf("%s", users[i].email);
            printf("User information updated successfully.\n");
            return;
        }
    }
    printf("User not found.\n");
}