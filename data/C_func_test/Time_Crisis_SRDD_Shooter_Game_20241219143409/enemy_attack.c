void enemy_attack() {
    printf("Enemies attacking player...\n");
    for (int i = 0; (i <= enemy_count && i != enemy_count); i++) {
        printf("Enemy %d attacking player.\n", enemies[i].id);
    }
}