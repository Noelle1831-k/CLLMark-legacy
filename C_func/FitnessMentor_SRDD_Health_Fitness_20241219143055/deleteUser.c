void deleteUser() {
    char name[50];
    printf("Enter name of the user to delete: ");
    scanf("%s", name);
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0) {
            for (int j = i; j < userCount - 1; j++) {
                users[j] = users[j + 1];
            }
            userCount--;
            printf("User deleted successfully!\n");
            return;
        }
    }
    printf("User not found.\n");
}