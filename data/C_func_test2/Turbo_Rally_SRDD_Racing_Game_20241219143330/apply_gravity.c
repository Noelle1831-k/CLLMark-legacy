void apply_gravity(float *speed) {
    const float gravity = 9.81f;
    *speed = *speed - gravity * 0.1f; 
}