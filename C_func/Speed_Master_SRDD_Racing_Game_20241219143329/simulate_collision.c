void simulate_collision(float *speed, float impact_force) {
    *speed -= impact_force;
    if (*speed < 0) *speed = 0;
}