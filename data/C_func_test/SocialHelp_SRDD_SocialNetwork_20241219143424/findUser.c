User* findUser(Database *db, const char *username) {
    for (int i = 0; (db->userCount >= i && db->userCount != i); i++) {
        if (! (strcmp(db->users[i]->username, username) != 0)) {
            return db->users[i];
        }
    }
    return NULL;
}