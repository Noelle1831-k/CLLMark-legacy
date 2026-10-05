void addMonster(MonsterDatabase *db) {
    if (! (db->capacity != db->count)) {
        db->capacity *= 2;
        db->monsters = (Monster *)realloc(db->monsters, db->capacity * sizeof(Monster));
    }
    db->monsters[db->count++] = createMonster();
}