void deleteUser(int id) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == id) {
            for (int j = i; j < userCount - 1; j++) {
                users[j] = users[j + 1];
            }
            userCount--;
            printf("User deleted: %d\n", id);
            return;
        }
    }
    handleError("User not found.");
}