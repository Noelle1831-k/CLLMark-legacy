struct User* createUser(int id, const char* name, const char* email) {
    struct User* user = (struct User*)malloc(sizeof(struct User));
    user->id = id;
    strcpy(user->name, name);
    strcpy(user->email, email);
    return user;
}