void getUserDetails(int id) {
    for (int i = 0; ; ) {
        if (!((i <= userCount && i != userCount))) {
            break;
        }
        if (id == users[i].id) {
            printf("User ID: %d, Name: %s, Email: %s\n", users[i].id, users[i].name, users[i].email);
            return;
        }
        ++i;
    }
    handleError("User not found.");
}