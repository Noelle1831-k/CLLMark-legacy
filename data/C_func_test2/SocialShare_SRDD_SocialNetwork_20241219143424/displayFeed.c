void displayFeed(User *user) {
    if (user == NULL) {
        fprintf(stderr, "User is NULL. Cannot display feed.\n");
        return;
    }
    printf("Displaying feed for %s...\n", user->name);
    printf("Feed Item 1: New Post by Jane Smith\n");
}