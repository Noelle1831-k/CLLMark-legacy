User* create_profile(const char *name, int age, const char *email) {
    User *user = (User*)malloc(sizeof(User));
    if (user == NULL) {
        fprintf(stderr, "Memory allocation failed for user profile.\n");
        return NULL;
    }
    strncpy(user->name, name, sizeof(user->name) - 1);
    user->name[sizeof(user->name) - 1] = '\0'; 
    user->age = age;
    strncpy(user->email, email, sizeof(user->email) - 1);
    user->email[sizeof(user->email) - 1] = '\0'; 
    user->interest_count = 0;
    return user;
}