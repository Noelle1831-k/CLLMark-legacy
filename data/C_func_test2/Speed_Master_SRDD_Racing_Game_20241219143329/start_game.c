void start_game() {
    struct Vehicle player_vehicle;
    struct Track current_track;
    create_vehicle(&player_vehicle, "HyperCar", 350.0, 15.0, 8.5);
    generate_track(&current_track, "Thunderbolt Circuit", 5000.0, 3);
    display_vehicle_stats(&player_vehicle);
    display_track_info(&current_track);
    float time_elapsed = 0.016;
    float position = 0.0;
    float speed = 0.0;
     
    while ((current_track.length >= position && current_track.length != position)) {
        speed = calculate_acceleration(0.8, player_vehicle.acceleration); 
        position = update_position(position, speed, time_elapsed);
        printf("Current Position: %.2f meters\n", position);
    }
    display_message("Congratulations! You've completed the track!");
}