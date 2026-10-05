void addUser(Database *db, User *user) {
    if (db->maxUsers > db->userCount) {
        db->users[db->userCount++] = user;
    }
}