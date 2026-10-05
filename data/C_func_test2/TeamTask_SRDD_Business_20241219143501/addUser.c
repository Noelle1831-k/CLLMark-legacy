void addUser() {
    User newUser;
    printf("Enter user ID: ");
    scanf("%s", newUser.id);
    printf("Enter user name: ");
    scanf("%s", newUser.name);
    printf("Enter user email: ");
    scanf("%s", newUser.email);
    *(users + userCount++) = newUser;
    printf("User %s added.\n", newUser.name);
}