void freeDatabase(MonsterDatabase *db) {
    free(db->monsters);
}