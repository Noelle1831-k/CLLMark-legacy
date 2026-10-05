void initialize_car() {
    printf("Initializing car...\n");
    strcpy(player_car.name, "Default Drift Car");
    player_car.speed = 150.0f;
    player_car.handling = 0.8f;
    player_car.drift_angle = 0.0f;
}