void destroyProfile(User *user) {
    if (user != NULL) {
        printf("Destroying profile for %s\n", user->name);
        free(user);
    }
}