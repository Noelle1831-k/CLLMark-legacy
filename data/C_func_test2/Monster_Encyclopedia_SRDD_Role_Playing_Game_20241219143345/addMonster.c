void addMonster(MonsterDatabase *db) {
    if (db->count == db->capacity) {
        db->capacity = db->capacity * 2;
        db->monsters = (Monster *)realloc(db->monsters, db->capacity * sizeof(Monster));
    }
    db->monsters[db->count++] = createMonster();
}