User* createUser(sqlite3 *db, const char *name, const char *industry, const char *role) {
    char *errMsg = 0;
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO USERS (NAME, INDUSTRY, ROLE) VALUES ('%s', '%s', '%s');", name, industry, role);
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("User %s created successfully.\n", name);
    }
    User *newUser = (User*)malloc(sizeof(User));
    strcpy(newUser->name, name);
    strcpy(newUser->industry, industry);
    strcpy(newUser->role, role);
    return newUser;
}