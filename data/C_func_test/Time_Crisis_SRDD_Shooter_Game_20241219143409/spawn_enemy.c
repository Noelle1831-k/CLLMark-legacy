void spawn_enemy(int x, int y) {
    if (enemy_count < 10) {
        enemies[enemy_count].id = enemy_count;
        enemies[enemy_count].x = x;
        enemies[enemy_count].y = y;
        enemies[enemy_count].health = 50;  
        printf("Enemy %d spawned at (%d, %d).\n", enemies[enemy_count].id, x, y);
        enemy_count++;
    } else {
        printf("Maximum enemy count reached!\n");
    }
}