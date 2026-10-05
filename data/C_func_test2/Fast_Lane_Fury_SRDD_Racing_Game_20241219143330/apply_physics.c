void apply_physics() {
    printf("Applying physics...\n");
    player.speed *= FRICTION; 
    if (player.speed > 0) {
        player.speed -= 0.1; 
    }
    update_player_position();
}