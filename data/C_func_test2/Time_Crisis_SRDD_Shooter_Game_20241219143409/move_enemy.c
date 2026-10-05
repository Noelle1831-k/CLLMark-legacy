void move_enemy(int enemy_id) {
    if (enemy_id < enemy_count) {
        printf("Moving enemy %d...\n", enemy_id);
        enemies[enemy_id].x += (rand() % 3 - 1);  
        enemies[enemy_id].y += (rand() % 3 - 1);  
        printf("Enemy %d moved to (%d, %d).\n", enemy_id, enemies[enemy_id].x, enemies[enemy_id].y);
    } else {
        printf("Invalid enemy ID: %d.\n", enemy_id);
    }
}