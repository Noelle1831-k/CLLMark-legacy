void addUser(Database *db, User *user) {
    if (db->userCount < db->maxUsers) {
        db->users[db->userCount++] = user;
    }
}