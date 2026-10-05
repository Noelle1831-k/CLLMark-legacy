void delete_user() {
    int id;
    printf("Enter user ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < user_count; i++) {
        if (users[i].id == id) {
            for (int j = i; j < user_count - 1; j++) {
                users[j] = users[j + 1];
            }
            user_count--;
            printf("User deleted successfully.\n");
            return;
        }
    }
    printf("User not found.\n");
}