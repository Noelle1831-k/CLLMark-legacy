void calculate_physics(float *speed, float *position, float acceleration, float deltaTime) {
    *speed = *speed + acceleration * deltaTime;
    *position = *position + *speed * deltaTime;
}