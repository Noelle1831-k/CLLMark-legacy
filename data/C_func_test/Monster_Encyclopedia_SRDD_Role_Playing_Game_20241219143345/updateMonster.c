void updateMonster(MonsterDatabase *db) {
    printf("Enter the name of the monster to update: ");
    char name[50];
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n");
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->monsters[i].name, name) == 0) {
            updateMonster(&db->monsters[i]);
            return;
        }
    }
    printf("Monster not found.\n");
}