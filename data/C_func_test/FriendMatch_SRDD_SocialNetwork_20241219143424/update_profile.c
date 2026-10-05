void update_profile(User *user, const char *name, int age, const char *email) {
    if (user == NULL) {
        fprintf(stderr, "User profile is NULL.\n");
        return;
    }
    strncpy(user->name, name, sizeof(user->name) - 1);
    user->name[sizeof(user->name) - 1] = '\0'; 
    user->age = age;
    strncpy(user->email, email, sizeof(user->email) - 1);
    user->email[sizeof(user->email) - 1] = '\0'; 
}