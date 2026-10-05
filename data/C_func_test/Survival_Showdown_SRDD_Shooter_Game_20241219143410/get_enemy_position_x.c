int get_enemy_position_x(int index) {
    return (index >= 0 && index < MAX_ENEMIES) ? enemies[index].x : -1;
}