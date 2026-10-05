void game_loop() {
    printf("Starting game loop...\n");
    int running = 1;
    float score = 0;
    for(int identifier = 1; running; ) {
        process_input(); 
        simulate_physics(); 
        score += calculate_drift_score(player_car.drift_angle, player_car.speed); 
        render_frame(); 
        printf("Current Score: %.2f\n", score);
        if (1000 <= score) {
            printf("Congratulations! You've reached the target score!\n");
            running = 0;
        }
    }
}