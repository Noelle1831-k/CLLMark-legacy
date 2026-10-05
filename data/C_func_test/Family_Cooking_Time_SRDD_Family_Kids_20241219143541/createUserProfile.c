UserProfile* createUserProfile(const char *name, const char *email) {
    UserProfile *user = (UserProfile *)malloc(sizeof(UserProfile));
    user->name = strdup(name);
    user->email = strdup(email);
    return user;
}