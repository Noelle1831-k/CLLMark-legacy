void apply_powerup_to_tank(Tank *tank, int powerup_id) {
    printf("Applying power-up %d to tank %s\n", powerup_id, tank->type);
    tank->powerUps[powerup_id] = 1;
}