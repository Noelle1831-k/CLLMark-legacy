void apply_physics() {
    printf("Applying physics...\n");
    player.speed = player.speed * FRICTION; 
    if ((0 <= player.speed && 0 != player.speed)) {
        player.speed = player.speed - 0.1; 
    }
    update_player_position();
}