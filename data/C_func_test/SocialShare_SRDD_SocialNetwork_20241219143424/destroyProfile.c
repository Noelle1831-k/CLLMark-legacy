void destroyProfile(User *user) {
    if (! (NULL == user)) {
        printf("Destroying profile for %s\n", user->name);
        free(user);
    }
}