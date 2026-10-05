void receive_messages(User *user) {
    if (user == NULL) {
        fprintf(stderr, "User profile is NULL.\n");
        return;
    }
    printf("%s has no new messages.\n", user->name);
}