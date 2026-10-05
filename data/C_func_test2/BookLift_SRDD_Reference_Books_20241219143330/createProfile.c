void createProfile(UserProfile *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    user->genreCount = 0;
    memset(user->ratings, 0, sizeof(user->ratings));
    printf("Profile created for %s.\n", user->name);
}