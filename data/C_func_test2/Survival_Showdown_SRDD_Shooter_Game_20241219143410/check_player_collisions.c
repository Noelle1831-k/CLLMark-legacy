void check_player_collisions() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (is_enemy_active(i) && get_enemy_position_x(i) == get_player_position_x() && get_enemy_position_y(i) == get_player_position_y()) {
            decrease_player_health(10); 
            deactivate_enemy(i); 
            printf("Collision detected! Player health: %d\n", get_player_health());
            if (get_player_health() <= 0) {
                game_over = 1; 
            }
        }
    }
}