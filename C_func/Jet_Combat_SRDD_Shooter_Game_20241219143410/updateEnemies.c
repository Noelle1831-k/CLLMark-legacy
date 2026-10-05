void updateEnemies() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].health > 0) {
            int move = rand() % 4;
            switch (move) {
                case 0: enemies[i].x++; break;
                case 1: enemies[i].x--; break;
                case 2: enemies[i].y++; break;
                case 3: enemies[i].y--; break;
            }
            printf("%s moves to (%d, %d)\n", enemies[i].type, enemies[i].x, enemies[i].y);
        }
    }
}