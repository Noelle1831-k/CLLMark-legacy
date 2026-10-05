void displayAllMonsters(MonsterDatabase *db) {
    for (int i = 0; i < db->count; i++) {
        displayMonster(&db->monsters[i]);
    }
}