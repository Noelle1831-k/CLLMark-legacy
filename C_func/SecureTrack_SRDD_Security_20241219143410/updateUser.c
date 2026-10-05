void updateUser(int id, const char *name, const char *email) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == id) {
            strcpy(users[i].name, name);
            strcpy(users[i].email, email);
            printf("User updated: %s\n", name);
            return;
        }
    }
    handleError("User not found.");
}