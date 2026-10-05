void deactivate_enemy(int index) {
    if (index >= 0 && index < MAX_ENEMIES) {
        enemies[index].active = 0;
    }
}