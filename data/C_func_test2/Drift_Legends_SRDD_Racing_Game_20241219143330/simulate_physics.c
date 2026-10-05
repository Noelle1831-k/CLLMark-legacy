void simulate_physics() {
    printf("Simulating physics...\n");
    player_car.drift_angle = fmod(player_car.drift_angle + 0.05f, 360.0f);
}