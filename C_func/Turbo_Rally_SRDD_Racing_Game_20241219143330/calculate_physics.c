void calculate_physics(float *speed, float *position, float acceleration, float deltaTime) {
    *speed += acceleration * deltaTime;
    *position += *speed * deltaTime;
}