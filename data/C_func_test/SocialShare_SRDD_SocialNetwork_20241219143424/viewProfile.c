void viewProfile(User *user) {
    if (user == NULL) {
        fprintf(stderr, "User profile is NULL.\n");
        return;
    }
    printf("User Profile:\nName: %s\nEmail: %s\nID: %d\n", user->name, user->email, user->id);
}