int get_enemy_position_y(int index) {
    return (index >= 0 && index < MAX_ENEMIES) ? enemies[index].y : -1;
}