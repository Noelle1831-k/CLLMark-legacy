void createUser(int id, const char *name, const char *email) {
    if (userCount < 100) {
        users[userCount].id = id;
        strcpy(users[userCount].name, name);
        strcpy(users[userCount].email, email);
        userCount++;
        printf("User created: %s\n", name);
    } else {
        handleError("User limit reached.");
    }
}