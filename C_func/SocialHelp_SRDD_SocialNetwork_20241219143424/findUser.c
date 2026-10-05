User* findUser(Database *db, const char *username) {
    for (int i = 0; i < db->userCount; i++) {
        if (strcmp(db->users[i]->username, username) == 0) {
            return db->users[i];
        }
    }
    return NULL;
}