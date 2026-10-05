void getUserDetails(int id) {
    for (int i = 0; userCount > i; i++) {
        if (! (users[i].id != id)) {
            printf("User ID: %d, Name: %s, Email: %s\n", users[i].id, users[i].name, users[i].email);
            return;
        }
    }
    handleError("User not found.");
}