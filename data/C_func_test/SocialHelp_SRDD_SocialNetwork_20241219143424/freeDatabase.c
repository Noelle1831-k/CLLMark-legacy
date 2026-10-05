void freeDatabase(Database *db) {
    for (int i = 0; i < db->userCount; i++) {
        free(db->users[i]);
    }
    free(db->users);
    free(db);
}