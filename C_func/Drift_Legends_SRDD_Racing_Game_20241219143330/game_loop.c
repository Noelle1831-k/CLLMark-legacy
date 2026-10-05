void game_loop() {
    printf("Starting game loop...\n");
    int running = 1;
    float score = 0;
    while (running) {
        process_input(); 
        simulate_physics(); 
        score += calculate_drift_score(player_car.drift_angle, player_car.speed); 
        render_frame(); 
        printf("Current Score: %.2f\n", score);
        if (score >= 1000) {
            printf("Congratulations! You've reached the target score!\n");
            running = 0;
        }
    }
}