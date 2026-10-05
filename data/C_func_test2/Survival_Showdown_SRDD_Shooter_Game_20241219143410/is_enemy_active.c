int is_enemy_active(int index) {
    return (index >= 0 && index < MAX_ENEMIES) ? enemies[index].active : 0;
}