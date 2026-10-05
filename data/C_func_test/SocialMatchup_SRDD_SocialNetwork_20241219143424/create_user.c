User* create_user(const char* name, const char* skills, const char* interests) {
    User* new_user = (User*)malloc(sizeof(User));
    if (new_user == NULL) {
        printf("Error allocating memory for new user.\n");
        exit(1);
    }
    strcpy(new_user->name, name);
    strcpy(new_user->skills, skills);
    strcpy(new_user->interests, interests);
    new_user->connections = NULL;
    new_user->num_connections = 0;
    return new_user;
}