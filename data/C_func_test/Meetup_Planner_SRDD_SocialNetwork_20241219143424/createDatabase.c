Database* createDatabase() {
    Database *db = (Database *)malloc(sizeof(Database));
    db->users = NULL;
    db->events = NULL;
    return db;
}