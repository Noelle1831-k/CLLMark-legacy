void simulate_shot(float *velocity, float *angle, float *direction) {
    *velocity = generate_shot_velocity();
    *angle = calculate_shot_angle();
    *direction = calculate_shot_direction(*velocity);
}