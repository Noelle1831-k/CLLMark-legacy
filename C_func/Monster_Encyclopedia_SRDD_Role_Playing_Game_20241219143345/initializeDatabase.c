void initializeDatabase(MonsterDatabase *db) {
    db->count = 0;
    db->capacity = 10;
    db->monsters = (Monster *)malloc(db->capacity * sizeof(Monster));
}