void init_user(User *user, const char *name, int age, const char *preferences) {
    strcpy(user->name, name);
    user->age = age;
    strcpy(user->preferences, preferences);
}