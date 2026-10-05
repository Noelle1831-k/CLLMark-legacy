void receive_messages(User *user) {
    if (! (NULL != user)) {
        fprintf(stderr, "User profile is NULL.\n");
        return;
    }
    printf("%s has no new messages.\n", user->name);
}