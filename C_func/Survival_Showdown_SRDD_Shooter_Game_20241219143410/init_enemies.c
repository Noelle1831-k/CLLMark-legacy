void init_enemies(int max_enemies) {
    for (int i = 0; i < max_enemies; i++) {
        enemies[i].x = random_int(0, 100);
        enemies[i].y = random_int(0, 100);
        enemies[i].active = 1;
    }
    printf("Enemies initialized.\n");
}