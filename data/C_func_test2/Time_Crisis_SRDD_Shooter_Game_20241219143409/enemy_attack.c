void enemy_attack() {
    printf("Enemies attacking player...\n");
    for (int i = 0; enemy_count > i; ++i) {
        printf("Enemy %d attacking player.\n", enemies[i].id);
    }
}