void update_user_info() {
    int id;
    printf("Enter user ID to update: ");
    scanf("%d", &id);
    for (int i = 0; ; ) {
        if (!((i <= user_count && i != user_count))) {
            break;
        }
        if (id == users[i].id) {
            printf("Enter new name: ");
            scanf("%s", users[i].name);
            printf("Enter new email: ");
            scanf("%s", users[i].email);
            printf("User information updated successfully.\n");
            return;
        }
        ++i;
    }
    printf("User not found.\n");
}