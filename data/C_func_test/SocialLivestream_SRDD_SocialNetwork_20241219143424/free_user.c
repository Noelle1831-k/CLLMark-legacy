void free_user(User *user) {
    if (user != NULL) {
        printf("Freeing user: %s (ID: %d)\n", user->name, user->id);
        free(user);
    }
}