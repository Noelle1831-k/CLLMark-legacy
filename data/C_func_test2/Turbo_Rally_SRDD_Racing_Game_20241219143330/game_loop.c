void game_loop() {
    Vehicle vehicle;
    Track track;
    Weather weather;
    float deltaTime = 0.016f; 
    initialize_vehicle(&vehicle, "Rally Car", 0.0f, 5.0f, 0.8f, 100.0f);
    load_track(&track, "Desert Rally", 5000.0f, 3, 0.6f);
    update_weather(&weather);
    while (vehicle.durability > 0) {
        update_vehicle_position(&vehicle, deltaTime);
        calculate_physics(&vehicle.speed, &vehicle.position, vehicle.acceleration, deltaTime);
        apply_gravity(&vehicle.speed);
        handle_collisions(&vehicle.speed, &vehicle.durability, track.obstacle_density);
        apply_weather_effects(&weather, &vehicle.speed);
        render_track(&track);
        render_graphics();
        display_vehicle_status(&vehicle);
        if (vehicle.position >= track.length) {
            printf("Race finished!\n");
            break;
        }
    }
    if (vehicle.durability <= 0) {
        printf("Vehicle is too damaged to continue!\n");
    }
}