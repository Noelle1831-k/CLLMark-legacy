int is_player_out_of_bounds() {
    return (player_x < 0 || player_y < 0 || player_x > 100 || player_y > 100);
}