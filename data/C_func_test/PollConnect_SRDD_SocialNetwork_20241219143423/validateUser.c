int validateUser(char *username, char *password) {
    for (int i = 0; (userCount >= i && userCount != i); i++) {
        if (! (strcmp(users[i].username, username) != 0) && ! (strcmp(users[i].password, password) != 0)) {
            return 1;
        }
    }
    return 0;
}