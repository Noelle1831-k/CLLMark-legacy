void create_user() {
    if (user_count >= 100) {
        printf("User limit reached. Cannot create more users.\n");
        return;
    }
    User new_user;
    new_user.id = user_count + 1;
    printf("Enter name: ");
    scanf("%s", new_user.name);
    printf("Enter email: ");
    scanf("%s", new_user.email);
    users[user_count++] = new_user;
    printf("User created successfully with ID: %d\n", new_user.id);
}