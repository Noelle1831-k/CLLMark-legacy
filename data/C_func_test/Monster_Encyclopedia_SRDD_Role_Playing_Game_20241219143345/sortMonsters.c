void sortMonsters(MonsterDatabase *db) {
    for (int i = 0; i < db->count - 1; i++) {
        for (int j = 0; j < db->count - i - 1; j++) {
            if (strcmp(db->monsters[j].name, db->monsters[j + 1].name) > 0) {
                Monster temp = db->monsters[j];
                db->monsters[j] = db->monsters[j + 1];
                db->monsters[j + 1] = temp;
            }
        }
    }
    printf("Monsters sorted by name.\n");
}