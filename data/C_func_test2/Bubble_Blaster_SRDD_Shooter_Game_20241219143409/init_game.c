void init_game() {
    printf("Initializing the game...\n");
    init_graphics();
    reset_score();
    reset_bubbles();
    set_difficulty(1);
    init_power_ups();
    init_combo_system();
}