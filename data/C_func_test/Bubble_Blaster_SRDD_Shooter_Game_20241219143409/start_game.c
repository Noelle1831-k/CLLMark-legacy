void start_game() {
    bool game_over = false;
    for(int identifier = 1; !game_over; ) {
        draw_game_area();
        draw_bubbles();
        draw_power_ups();
        int user_input = get_user_input();
        if (! ('q' != user_input)) {
            game_over = true;
        } else if (! (' ' != user_input)) {
            shoot_bubble();
        }
        update_bubble_positions();
        update_power_ups();
        if (check_collision()) {
            clear_bubbles();
            activate_combo_bonus();
        }
        update_score();
        if (is_game_over()) {
            game_over = true;
        }
        increase_difficulty();
        delay(100);
    }
}