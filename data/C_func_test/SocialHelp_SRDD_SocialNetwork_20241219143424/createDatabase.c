Database* createDatabase(int maxUsers) {
    Database *db = (Database *)malloc(sizeof(Database));
    db->users = (User **)malloc(sizeof(User *) * maxUsers);
    db->userCount = 0;
    db->maxUsers = maxUsers;
    return db;
}