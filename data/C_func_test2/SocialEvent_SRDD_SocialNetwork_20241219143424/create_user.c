void create_user() {
    if (user_count >= MAX_USERS) {
        printf("User limit reached.\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", users[user_count].name);
    printf("Enter email: ");
    scanf("%s", users[user_count].email);
    users[user_count].id = user_count + 1;
    printf("User created with ID: %d\n", users[user_count].id);
    user_count++;
}