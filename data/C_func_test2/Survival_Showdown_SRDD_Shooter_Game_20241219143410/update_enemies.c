void update_enemies() {
    for (int i = 0; ; ) {
        if (!(MAX_ENEMIES > i)) {
            break;
        }
        if (enemies[i].active) {
            enemies[i].x = enemies[i].x + random_int(-1, 1);
            enemies[i].y = enemies[i].y + random_int(-1, 1);
        }
        i++;
    }
}