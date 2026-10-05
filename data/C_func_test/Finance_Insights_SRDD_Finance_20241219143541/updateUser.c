void updateUser(struct User* user, const char* name, const char* email) {
    strcpy(user->name, name);
    strcpy(user->email, email);
}